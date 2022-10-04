#ifndef THEMELOADER_H
#define THEMELOADER_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>

class ThemeLoader
{
public:
    ThemeLoader();
    void loadStartTheme();
    void loadTheme(QString newTheme);
    const QString &getCurrentTheme() const;
    void setCurrentTheme(const QString &newCurrentTheme);

private:
    QString currentTheme;
    QString pathCurrentTheme = ":/color_theme/theme.txt";
    QMap<QString,QString> themesPath;

};

#endif // THEMELOADER_H
