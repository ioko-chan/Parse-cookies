#include "cookieparser.h"

CookieParser::CookieParser(const QString &cookiesTxt)
{
    parseCookies(cookiesTxt);
    buildTreeCookies();
}

void CookieParser::parseCookies(const QString &cookiesTxt)
{
    QJsonDocument doc =  QJsonDocument::fromJson(cookiesTxt.toUtf8());
    QJsonArray jsonArray = doc.array();

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

            cookies.append(cookie);
            setParsedCookies(getParsedCookies()+1);
        }
    }
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

 int CookieParser::getParsedCookies() const
 {
     return parsedCookies;
 }

 void CookieParser::setParsedCookies(int newParsedCookies)
 {
     parsedCookies = newParsedCookies;
 }

 void CookieParser::buildTreeCookies()
 {
     foreach(const Cookie &cookie, getCookies())
     {
         treeCookies[cookie.getDomain()].append(cookie);
     }
 }

 const QList<Cookie> &CookieParser::getCookies() const
 {
     return cookies;
 }

 void CookieParser::setCookies(const QList<Cookie> &newCookies)
 {
     cookies = newCookies;
 }

 const QMap<QString, QList<Cookie> > &CookieParser::getTreeCookies() const
 {
     return treeCookies;
 }

 void CookieParser::setTreeCookies(const QMap<QString, QList<Cookie> > &newTreeCookies)
 {
     treeCookies = newTreeCookies;
 }
