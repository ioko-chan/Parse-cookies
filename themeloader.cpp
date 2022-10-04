#include "themeloader.h"

ThemeLoader::ThemeLoader()
{
    themesPath.insert("Light",":/qss/style.qss" );
    themesPath.insert("Dark",":/qss/style_black.qss" );
}

void ThemeLoader::loadStartTheme()
{
    QFile themeFile(pathCurrentTheme);
    themeFile.open(QFile::ReadOnly);
    if(themeFile.isOpen())
    {
        QTextStream stream(&themeFile);
        currentTheme = stream.readLine();
        themeFile.close();
    }
    else
    {
        qDebug() << "Не может открыть файл начальной темы";
        return;
    }
    loadTheme(currentTheme);
}

void ThemeLoader::loadTheme(QString newTheme)
{
    QString path = themesPath[newTheme];
    QFile qssFile(path);
       qssFile.open(QFile::ReadOnly);
       if(qssFile.isOpen())
       {
           QString qss = QLatin1String(qssFile.readAll());
           qApp->setStyleSheet(qss);
           qssFile.close();
       }
       else
       {
           qDebug() << "Не может открыть файл стиля";
           return;
       }

       QFile themeFile(pathCurrentTheme);
       themeFile.open(QFile::ReadWrite);
       if(themeFile.isOpen())
       {
           QTextStream stream(&themeFile);
           stream << newTheme ;
           themeFile.close();
       }

}

const QString &ThemeLoader::getCurrentTheme() const
{
    return currentTheme;
}

void ThemeLoader::setCurrentTheme(const QString &newCurrentTheme)
{
    currentTheme = newCurrentTheme;
}
