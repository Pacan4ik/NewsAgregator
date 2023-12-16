#ifndef PARSEDNEWS_H
#define PARSEDNEWS_H

#include <QString>
#include <QDateTime>

class ParsedNews
{
public:
    ParsedNews();
    ParsedNews(QString link, QString title, QString description, QDateTime pubDate, QString source);
    ParsedNews(QString link, QString title, QString description, QString pubDate, QString source);
    QString getLink() const;
    void setLink(const QString &value);


    QString getTitle() const;
    void setTitle(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QDateTime getPubDate() const;
    void setPubDate(const QDateTime &value);

    QString getSource() const;
    void setSource(const QString &value);

private:
    QString link;
    QString title;
    QString description;
    QDateTime pubDate;
    QString source;
    QDateTime convertDate(const QString &value) const;
};

#endif // PARSEDNEWS_H
