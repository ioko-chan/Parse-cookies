#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uploadfile.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setFilesLoader(FilesLoader *newFilesLoader);
    void updateListView(QString *path);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    FilesLoader *filesLoader;
};
#endif // MAINWINDOW_H
