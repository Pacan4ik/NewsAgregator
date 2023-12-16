#include "allnewstab.h"
#include "ui_allnewstab.h"
#include <QDesktopServices>
#include "xmlnewsreader.h"
#include <algorithm>

AllNewsTab::AllNewsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllNewsTab)
{
    ui->setupUi(this);
    allNews = new QList<NewsItem*>();
    connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(onSearchButtonClicked()));
    connect(ui->refreshButton, SIGNAL(clicked()), this, SLOT(onRefreshButtonClicked()));
}

AllNewsTab::~AllNewsTab()
{
    clearAllNews();
    clearList();
    delete ui;
}

//Получение результатов парсинга
void AllNewsTab::getParsedNews(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
            return;

    Parser *parser = new XmlNewsReader(reply->readAll());
    parser->read();
    foreach(ParsedNews parsedItem, parser->getParsedNewsList()) {
        NewsItem * newsItem = new NewsItem();
        newsItem->setName(parsedItem.getTitle());
        newsItem->setText(parsedItem.getDescription());
        newsItem->setLink(parsedItem.getLink());
        newsItem->setPubDate(parsedItem.getPubDate());
        newsItem->setSource(parsedItem.getSource());
        allNews->append(newsItem);
    }
}

//Сортировка и отображение результатов
void AllNewsTab::onFinishXMLParse()
{

    std::sort(allNews->begin(), allNews->end(), [](const NewsItem* news1, const NewsItem* news2) {
        return news1->getPubDate() < news2->getPubDate();
    });

    foreach (NewsItem* newsitem, (*allNews)) {
        QListWidgetItem * widgetItem = new QListWidgetItem;
        NewsItem *copiedItem = new NewsItem(*newsitem);
        addItemToList(widgetItem, copiedItem);
    }
}

//Добавление нового виджета в список
void AllNewsTab::addItemToList(QListWidgetItem *item, NewsItem* news)
{
    item->setSizeHint(QSize(0, 130));
    ui->newsListWidget->addItem(item);
    ui->newsListWidget->setItemWidget(item, transformToWidget(news));
}

//NewsItem -> QWidget
QWidget *AllNewsTab::transformToWidget(NewsItem * news)
{
    NewsItem *w = new NewsItem(*news);
    connect(w, SIGNAL(readItemNews(QString)), this, SLOT(readNews(QString)));
    return w;
}

//поиск
void AllNewsTab::searchNews(const QString& searchTerm)
{
    clearList();

    for (NewsItem* news : (*allNews)) {
        if (news->getName().contains(searchTerm, Qt::CaseInsensitive) ||
            news->getText().contains(searchTerm, Qt::CaseInsensitive) ||
            news->getSource().contains(searchTerm, Qt::CaseInsensitive))
            {
            QListWidgetItem* item = new QListWidgetItem;
            addItemToList(item, news);
        }
    }

}

//загрузка новостей по списку ссылок
void AllNewsTab::loadNews(const QStringList& urls)
{
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
    QEventLoop loop;
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));

    for (const QString& url : urls) {
        QNetworkRequest request(url);
        QNetworkReply* currentReply = networkManager->get(request);
        loop.exec();
        getParsedNews(currentReply);
    }
    onFinishXMLParse();
}


//удаление виджетов
void AllNewsTab::clearList()
{
    ui->newsListWidget->clear();
}
//удаление новостей
void AllNewsTab::clearAllNews()
{
    allNews->clear();
}

//открытие ссылки
void AllNewsTab::readNews(QString link)
{
    QDesktopServices::openUrl(QUrl(link));
}

//поиск
void AllNewsTab::onSearchButtonClicked()
{
    QString searchTerm = ui->searchTextEdit->text();
    searchNews(searchTerm);
}

//обновление
void AllNewsTab::onRefreshButtonClicked()
{
    emit requestUpdateNews();
}
