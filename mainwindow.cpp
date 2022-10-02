#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

bool MainWindow::isExistsFilePathInListView(QString *path)
{
      QList<QListWidgetItem*> listPath = ui->listWidget->findItems(*path,Qt::MatchCaseSensitive);
      if(listPath.size()>0)
      {
          return true;
      }
      return false;
}


void MainWindow::on_pushButton_clicked()
{
    QString pathFile = QFileDialog::getOpenFileName
           (0,QObject::tr("Select file cookies"), QDir::homePath() , QObject::tr("Текстовый файл (*.txt)"));

    if(!isExistsFilePathInListView(&pathFile))
    {
        FileLoader fileLoader(pathFile);
        CookieParser cookieParser(fileLoader.getFileData());
        updateListView(&pathFile);
        updateLabelParsedCookies(cookieParser.getParsedCookies());
        updateTreeWidget(cookieParser.getTreeCookies());
    }
    else
    {
        QMessageBox::information(0,"Info", "This file already been loaded");
    }
}

void MainWindow::updateListView(QString *path)
{
    ui->listWidget->addItem(*path);
}

void MainWindow::updateTreeWidget(QMap<QString, QList<Cookie>> treeCookies)
{

    for(auto domain: treeCookies.keys())
    {
        QTreeWidgetItem *itemDomain = new QTreeWidgetItem();
        itemDomain->setText(0,domain);
        ui->treeWidget->addTopLevelItem(itemDomain);

        foreach(const Cookie &cookie, treeCookies.value(domain))
        {
            QTreeWidgetItem *itemName = new QTreeWidgetItem();
            itemName->setText(0,cookie.getName());
            itemDomain->addChild(itemName);

            QTreeWidgetItem *itemValue = new QTreeWidgetItem();
            itemValue->setText(0,"Value: " + cookie.getValue());

            QTreeWidgetItem *itemPath = new QTreeWidgetItem();
            itemPath->setText(0,"Path: " + cookie.getPath());

            QTreeWidgetItem *itemExpires = new QTreeWidgetItem();
            itemExpires->setText(0, "Expires: " + QString::number(cookie.getExpires()));

            QTreeWidgetItem *itemisHttpOnly = new QTreeWidgetItem();
            itemisHttpOnly->setText(0,"isHttpOnly: " + QVariant(cookie.getIsHttpOnly()).toString());

            QTreeWidgetItem *itemisSecure = new QTreeWidgetItem();
            itemisSecure->setText(0,"isSecure: " + QVariant(cookie.getIsSecure()).toString());

            itemName->addChild(itemValue);
            itemName->addChild(itemPath);
            itemName->addChild(itemExpires);
            itemName->addChild(itemisHttpOnly);
            itemName->addChild(itemisSecure);
        }

    }
}

void MainWindow::updateLabelParsedCookies(int cookies)
{
    ui->label_2->setText(QString::number(cookies));
}
