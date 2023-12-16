#ifndef XMLNEWSREADER_H
#define XMLNEWSREADER_H

#include <QByteArray>
#include <QList>
#include <QString>
#include "parsednews.h"
#include "parser.h"
#include "tinyxml2.h"

class XmlNewsReader : public Parser
{
public:
    XmlNewsReader(QByteArray byteArray);

    void read();
    QString errorString();

    QList<ParsedNews> getParsedNewsList() const;

private:
    void processNews(tinyxml2::XMLElement* item);
    QString sourceTitleStr;
    QByteArray inputByteArray;
    QList<ParsedNews> parsedNewsList;
};

#endif // XMLNEWSREADER_H
