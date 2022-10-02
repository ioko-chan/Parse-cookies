#include "cookieparser.h"

CookieParser::CookieParser()
{

}

void CookieParser::parseCookies(const QString &pathCookies,const QString &cookiesTxt)
{
    QJsonDocument doc =  QJsonDocument::fromJson(cookiesTxt.toUtf8());
    QJsonArray jsonArray = doc.array();
    QList<Cookie> listCookie;

    foreach (const QJsonValue & value, jsonArray)
    {
        if (value.isObject())
        {
            QJsonObject obj = value.toObject();
            Cookie cookie;

            QString domain = obj["domain"].toString();
            cookie.setDomain(domain);

            int expires = obj["expirationDate"].toInt();
            cookie.setExpires(expires);

            bool isHttpOnly = obj["httpOnly"].toBool();
            cookie.setIsHttpOnly(isHttpOnly);

            QString name = obj["name"].toString();
            cookie.setName(name);

            QString path = obj["path"].toString();
            cookie.setPath(path);

            bool isSecure = obj["secure"].toBool();
            cookie.setIsSecure(isSecure);

            QString value = obj["value"].toString();
            cookie.setValue(value);

            listCookie.append(cookie);
        }
    }
    cookies.insert(pathCookies, listCookie);
    listCookie.clear();
}

 bool CookieParser::isItCanBeParsed(const QString &cookiesTxt)
 {
     QJsonParseError error;
     QJsonDocument doc =  QJsonDocument::fromJson(cookiesTxt.toUtf8(),&error);
     if(error.error)
     {
          QMessageBox::critical(0,"Error", "This file cannot be parsed!");
          return false;
     }
     return true;
 }
