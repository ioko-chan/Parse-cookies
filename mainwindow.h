#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uploadfile.h"
#include "cookieparser.h"
#include <QMainWindow>
#include "QFileDialog"
#include "QMessageBox"

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
    void updateTreeWidget(QMap<QString, QList<Cookie>> treeCookies);
    void updateLabelParsedCookies(int cookies);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
