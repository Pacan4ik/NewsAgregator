#include "parsednews.h"
ParsedNews::ParsedNews(QString link, QString title, QString description, QDateTime pubDate, QString source)
    : link(link), title(title), description(description), pubDate(pubDate), source(source)
{
}

ParsedNews::ParsedNews(QString link, QString title, QString description, QString pubDate, QString source)
    : ParsedNews(link, title, description, convertDate(pubDate), source)
{
}


QString ParsedNews::getLink() const
{
    return link;
}

void ParsedNews::setLink(const QString &value)
{
    link = value;
}

QString ParsedNews::getTitle() const
{
    return title;
}

void ParsedNews::setTitle(const QString &value)
{
    title = value;
}

QString ParsedNews::getDescription() const
{
    return description;
}

void ParsedNews::setDescription(const QString &value)
{
    description = value;
}

QDateTime ParsedNews::getPubDate() const
{
    return pubDate;
}

QDateTime ParsedNews::convertDate(const QString &value) const
{
    QDateTime dateTime;
    dateTime = QDateTime::fromString(value, "ddd, dd MMM yyyy hh:mm:ss t");
    if (!dateTime.isValid()) {
        dateTime = QDateTime::fromString(value, "ddd, dd MMM yyyy hh:mm:ss 'GMT'");
    }
    if (!dateTime.isValid()) {
        dateTime = QDateTime();
    }
    return dateTime;
}


void ParsedNews::setPubDate(const QDateTime &value)
{
    pubDate = value;
}

QString ParsedNews::getSource() const
{
    return source;
}
void ParsedNews::setSource(const QString &value)
{
    source = value;
}
