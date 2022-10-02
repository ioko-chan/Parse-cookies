#include "cookie.h"

Cookie::Cookie()
{

}

QString Cookie::getDomain() const
{
    return domain;
}

void Cookie::setDomain(QString newDomain)
{
    domain = newDomain;
}

int Cookie::getExpires() const
{
    return expires;
}

void Cookie::setExpires(int newExpires)
{
    expires = newExpires;
}

bool Cookie::getIsHttpOnly() const
{
    return isHttpOnly;
}

void Cookie::setIsHttpOnly(bool newIsHttpOnly)
{
    isHttpOnly = newIsHttpOnly;
}

QString Cookie::getName() const
{
    return name;
}

void Cookie::setName(QString newName)
{
    name = newName;
}

QString Cookie::getPath() const
{
    return path;
}

void Cookie::setPath(QString newPath)
{
    path = newPath;
}

bool Cookie::getIsSecure() const
{
    return isSecure;
}

void Cookie::setIsSecure(bool newIsSecure)
{
    isSecure = newIsSecure;
}

QString Cookie::getValue() const
{
    return value;
}

void Cookie::setValue(QString newValue)
{
    value = newValue;
}

