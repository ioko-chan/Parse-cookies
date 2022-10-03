#ifndef THEMELOADER_H
#define THEMELOADER_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QApplication>

class ThemeLoader
{
public:
    ThemeLoader();
    void loadStartTheme();
    void loadTheme(QString newTheme);
private:
    QString currentTheme;
    QMap<QString,QString> themesPath;

};

#endif // THEMELOADER_H
