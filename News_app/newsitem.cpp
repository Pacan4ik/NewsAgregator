#include "newsitem.h"
#include "ui_newsitem.h"

NewsItem::NewsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
}

NewsItem::NewsItem(QString name, QString text, QString link, QDateTime pubDate, QString source, QWidget *parent):
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
    this->name = name;
    this->text = text;
    this->link = link;
    this->pubDate = pubDate;
    this->source = source;
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
    ui->timeLabel->setText(pubDate.toString("hh:mm dd.MM.yyyy"));
    ui->sourceLabel->setText(this->source);
}

NewsItem::NewsItem(const NewsItem & other, QWidget *parent):
    QWidget(parent),
    ui(new Ui::NewsItem)
{
    ui->setupUi(this);
    this->name = other.name;
    this->text = other.text;
    this->link = other.link;
    this->source = other.source;
    this->pubDate = other.pubDate;
    ui->newsTitle->setText(this->name);
    ui->textBrowser->setText(this->text);
    ui->timeLabel->setText(pubDate.toString("hh:mm dd.MM.yyyy"));
    ui->sourceLabel->setText(this->source);
}

NewsItem NewsItem::operator=(const NewsItem &other) const
{
    NewsItem* newNews = new NewsItem(other.name, other.text, other.link, other.pubDate, other.source);
    return (* newNews);
}

void NewsItem::setName(QString name)
{
    this->name = name;
    ui->newsTitle->setText(this->name);
}

void NewsItem::setText(QString text)
{
    this->text = text;
    ui->textBrowser->setText(this->text);
}

void NewsItem::setPubDate(QDateTime pubDate)
{
    this->pubDate = pubDate;
    ui->timeLabel->setText(pubDate.toString("hh:mm dd.MM.yyyy"));
}

void NewsItem::setSource(QString source)
{
    this->source = source;
    ui->sourceLabel->setText(this->source);
}

QString NewsItem::getName() const
{
    return this->name;
}

QString NewsItem::getText() const
{
    return this->text;
}

QString NewsItem::getSource() const
{
    return this->source;
}
QDateTime NewsItem::getPubDate() const
{
    return pubDate;
}


NewsItem::~NewsItem()
{
    delete ui;
}

void NewsItem::on_readButton_clicked()
{
    emit readItemNews(this->link);
}


QString NewsItem::getLink() const
{
    return link;
}

void NewsItem::setLink(const QString &value)
{
    link = value;
}

