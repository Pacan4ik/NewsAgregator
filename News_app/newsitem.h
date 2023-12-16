#ifndef NEWSITEM_H
#define NEWSITEM_H

#include <QWidget>
#include <QString>
#include <QDateTime>
namespace Ui {
class NewsItem;
}

class NewsItem : public QWidget
{
    Q_OBJECT

public:
    explicit NewsItem(QWidget *parent = 0);
    explicit NewsItem(QString name, QString text, QString link, QDateTime pubDate, QString source, QWidget *parent = 0);
    NewsItem(const NewsItem&, QWidget *parent = 0);
    NewsItem operator=(const NewsItem& other) const;
    void setName(QString);
    void setText(QString);
    void setPubDate(QDateTime);
    void setSource(QString);
    QString getName() const;
    QString getText() const;
    QString getSource() const;
    QDateTime getPubDate() const;
    ~NewsItem();

    QString getLink() const;
    void setLink(const QString &value);

private slots:
    void on_readButton_clicked();

signals:
    void readItemNews(QString newsLink);
private:
    Ui::NewsItem *ui;
    QString text;
    QString name;
    QString link;
    QDateTime pubDate;
    QString source;

};
#endif // NEWSITEM_H
