#ifndef PARSER_H
#define PARSER_H

#include <QList>
#include <QString>
#include "parsednews.h"

class Parser
{
protected:
    Parser();
public:
    virtual ~Parser();

    virtual void read();
    virtual QList<ParsedNews> getParsedNewsList() const = 0;
};

#endif // PARSER_H
