#ifndef ALLNEWSTAB_H
#define ALLNEWSTAB_H

#include <QWidget>
#include <QListWidgetItem>
#include "newsitem.h"
#include <QList>
#include <QtNetwork>


namespace Ui {
class AllNewsTab;
}

class AllNewsTab : public QWidget
{
    Q_OBJECT



public:
    explicit AllNewsTab(QWidget *parent = 0);
    ~AllNewsTab();
    void addItemToList(QListWidgetItem* item, NewsItem* news);

    QWidget * transformToWidget(NewsItem *);
    void clearList();
    void clearAllNews();
    void searchNews(const QString& searchTerm);

private:
    Ui::AllNewsTab *ui;
    QList<NewsItem*> *allNews;
    void onFinishXMLParse();

private slots:
    void getParsedNews(QNetworkReply* reply);

    void readNews (QString link);
    void onSearchButtonClicked();
    void onRefreshButtonClicked();

public slots:
    void loadNews(const QStringList& urls);

signals:
    void readNewsSignal(QString link);
    void requestUpdateNews();
};

#endif // ALLNEWSTAB_H
