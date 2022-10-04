#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uploadfile.h"
#include "cookieparser.h"
#include "settingswindow.h"
#include <QMainWindow>
#include <QTreeWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isExistsFilePathInListView(QString *path);
    void updateListView(QString *path);
    void updateTreeWidget(const QString &path,QMap<QString, QList<Cookie>> treeCookies);
    void updateTreeWidget(QTreeWidget treeCookies);
    void updateLabelParsedCookies(int cookies);


private slots:
    void on_pushButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QMap<QString,QMap<QString, QList<Cookie>>> *treeCookieMap;
    QMap<QString,int> *parsedCookiesCount;
    QString *viewPath;
    SettingsWindow *settings;
};
#endif // MAINWINDOW_H
