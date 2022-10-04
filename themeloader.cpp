#include "themeloader.h"

ThemeLoader::ThemeLoader()
{
    themesPath.insert("Light",":/qss/style.qss" );
    themesPath.insert("Dark",":/qss/style_black.qss" );
}

void ThemeLoader::loadStartTheme()
{
    QFile themeFile("theme.txt");
    if(!themeFile.open(QIODevice::ReadWrite) || themeFile.readAll() == "")
    {
        themeFile.open(QIODevice::ReadWrite | QIODevice::Text);
        themeFile.seek(0);
        themeFile.write("Light");
    }
    themeFile.seek(0);
    currentTheme = themeFile.readAll();
    qDebug() << currentTheme;
    themeFile.close();
    loadTheme(currentTheme);
}

void ThemeLoader::loadTheme(QString newTheme)
{
    currentTheme = newTheme;
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
}

void ThemeLoader::wtiteThemeInFile()
{
    QFile themeFile("theme.txt");
    if(themeFile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&themeFile);
        stream << currentTheme ;
        themeFile.close();
    }
    else
    {
        qDebug()<<"Ooops...";
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
