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
    cookieParser = new CookieParser();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString pathFile = QFileDialog::getOpenFileName
           (0,QObject::tr("Select file cookies"), QDir::homePath() , QObject::tr("Текстовый файл (*.txt; *.json)"));

    if(filesLoader->loadFile(pathFile) && cookieParser->isItCanBeParsed(filesLoader->getCurrentFile()))
    {
         cookieParser->parseCookies(pathFile,filesLoader->getCurrentFile());
         updateListView(&pathFile);
    }
}

void MainWindow::updateListView(QString *path)
{
    ui->listWidget->addItem(*path);
}
