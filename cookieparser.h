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
    CookieParser();
    void parseCookies(const QString &pathCookies,const QString &cookiesTxt);
    bool isItCanBeParsed(const QString &cookiesTxt);

private:
    QMap< QString,QList<Cookie>> cookies;
};

#endif // COOKIEPARSER_H
