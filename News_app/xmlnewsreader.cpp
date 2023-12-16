#include "xmlnewsreader.h"
#include <QDebug>
#include "tinyxml2.h"


XmlNewsReader::XmlNewsReader(QByteArray byteArray)
{
    this->inputByteArray = byteArray;
}

void XmlNewsReader::read()
{
    tinyxml2::XMLDocument doc;
    if (doc.Parse(inputByteArray.constData()) == tinyxml2::XML_SUCCESS) {
        tinyxml2::XMLElement* root = doc.RootElement()->FirstChildElement("channel");
        const char* sourceTitle = root->FirstChildElement("title") ? root->FirstChildElement("title")->GetText() : "";
        sourceTitleStr = QString::fromUtf8(sourceTitle);
        for (tinyxml2::XMLElement* item = root->FirstChildElement("item"); item; item = item->NextSiblingElement("item")) {
            processNews(item);
        }
    }
    else {
        qDebug() << "Error parsing XML.";
    }
}


void XmlNewsReader::processNews(tinyxml2::XMLElement* item)
{
    if (!item) {
        return;
    }

    const char* title = item->FirstChildElement("title") ? item->FirstChildElement("title")->GetText() : "";
    const char* link = item->FirstChildElement("link") ? item->FirstChildElement("link")->GetText() : "";
    const char* description = item->FirstChildElement("description") ? item->FirstChildElement("description")->GetText() : "";
    const char* pubDate = item->FirstChildElement("pubDate") ? item->FirstChildElement("pubDate")->GetText() : "";


        QString titleStr = QString::fromUtf8(title);
        QString linkStr = QString::fromUtf8(link);
        QString descStr = QString::fromUtf8(description);

        ParsedNews* newsItem = new ParsedNews(linkStr, titleStr, descStr, pubDate, sourceTitleStr);
        this->parsedNewsList.append(*newsItem);
}

QString XmlNewsReader::errorString()
{
    return "Something was going wrong";
}

QList<ParsedNews> XmlNewsReader::getParsedNewsList() const
{
    return parsedNewsList;
}
