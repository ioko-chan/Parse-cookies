#ifndef COOKIES_H
#define COOKIES_H

#include <QString>


class Cookie
{
public:
    Cookie();

    QString getDomain() const;
    void setDomain(QString newDomain);

    int getExpires() const;
    void setExpires(int newExpires);

    bool getIsHttpOnly() const;
    void setIsHttpOnly(bool newIsHttpOnly);

    QString getName() const;
    void setName(QString newName);

    QString getPath() const;
    void setPath(QString newPath);

    bool getIsSecure() const;
    void setIsSecure(bool newIsSecure);

    QString getValue() const;
    void setValue(QString newValue);

private:
    QString domain;
    int expires;
    bool isHttpOnly;
    QString name;
    QString path;
    bool isSecure;
    QString value;
};

#endif // COOKIES_H
