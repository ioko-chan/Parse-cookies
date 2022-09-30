#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // написать класс сериализации и туды передававать этот путь
    // отсюда передать путь или название файла в список загруженных файлов
    QString pathFile = QFileDialog::getOpenFileName(0,QObject::tr("Select file cookies"), QDir::homePath() , QObject::tr("Текстовый файл (*.txt);;Все файлы (*.*)"));
}
