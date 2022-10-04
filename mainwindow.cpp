#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    treeCookieMap = new   QMap<QString,QMap<QString, QList<Cookie>>>;
    viewPath = new QString();
    parsedCookiesCount = new QMap<QString,int>();
    settings = new SettingsWindow();
    connect(settings , &SettingsWindow::mainWindow, this , &MainWindow::show);
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
          QMessageBox::information(0,"Info", "This file already been loaded");
          return true;
      }

      return false;
}

void MainWindow::on_pushButton_clicked()
{
    QString pathFile = QFileDialog::getOpenFileName
           (0,QObject::tr("Select file cookies"), QDir::homePath() , QObject::tr("Текстовый файл (*.txt)"));

    FileLoader fileLoader(pathFile);
    *viewPath = pathFile;
    CookieParser cookieParser(fileLoader.getFileData());
    if((!isExistsFilePathInListView(&pathFile)) && (cookieParser.isItCanBeParsed(fileLoader.getFileData())))
    {
        QMap<QString, QList<Cookie>> newTree;
        newTree = cookieParser.getTreeCookies();
        treeCookieMap->insert(pathFile,newTree);
        parsedCookiesCount->insert(pathFile, cookieParser.getParsedCookies());
        updateListView(&pathFile);
        updateLabelParsedCookies(cookieParser.getParsedCookies());
        updateTreeWidget(pathFile,cookieParser.getTreeCookies());
    }
}


void MainWindow::updateListView(QString *path)
{
    ui->listWidget->addItem(*path);
}

void MainWindow::updateTreeWidget(const QString &path,QMap<QString, QList<Cookie>> treeCookies)
{
    ui->treeWidget->clear();
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


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString path = item->text();
    if(*viewPath == path)
    {
        return;
    }
    *viewPath= path;
    ui->treeWidget->clear();
    updateTreeWidget(path,treeCookieMap->value(path));
    updateLabelParsedCookies(parsedCookiesCount->value(path));
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    settings->show();
}

