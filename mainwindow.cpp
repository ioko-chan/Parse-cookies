#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filesLoader = new FilesLoader();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString pathFile = QFileDialog::getOpenFileName
           (0,QObject::tr("Select file cookies"), QDir::homePath() , QObject::tr("Текстовый файл (*.txt)"));

    if(!filesLoader->isExistsIntoList(pathFile))
    {
         filesLoader->addNewPath(pathFile);
         updateListView(&pathFile);
         filesLoader->clearCurrentFile();
         filesLoader->readFile(pathFile);
    }
    else
    {
         QMessageBox::information(0, "Info","This file has already been uploaded. \nSelect another file");
    }

}

void MainWindow::setFilesLoader(FilesLoader *newFilesLoader)
{
    filesLoader = newFilesLoader;
}

void MainWindow::updateListView(QString *path)
{
    ui->listWidget->addItem(*path);
}
