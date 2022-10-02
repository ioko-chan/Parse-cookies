#ifndef COOKIEPARSER_H
#define COOKIEPARSER_H

#include "cookie.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QPair>
#include <QMessageBox>


class CookieParser
{
public:
    CookieParser(const QString &cookiesTxt);

    void parseCookies(const QString &cookiesTxt);
    bool isItCanBeParsed(const QString &cookiesTxt);

    int getParsedCookies() const;
    void setParsedCookies(int newParsedCookies);

    const QList<Cookie> &getCookies() const;
    void setCookies(const QList<Cookie> &newCookies);

    const QMap<QString, QList<Cookie> > &getTreeCookies() const;
    void setTreeCookies(const QMap<QString, QList<Cookie> > &newTreeCookies);
    void buildTreeCookies();

private:
    QList<Cookie> cookies;
    QMap<QString,QList<Cookie>> treeCookies;
    int parsedCookies = 0;
};

#endif // COOKIEPARSER_H
