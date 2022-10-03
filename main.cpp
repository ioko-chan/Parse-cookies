#include "mainwindow.h"
#include <QApplication>
#include "themeloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThemeLoader themeLoader;
    themeLoader.loadStartTheme();
    MainWindow w;
    w.show();
    return a.exec();
}
