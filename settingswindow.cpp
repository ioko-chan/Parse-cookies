#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    themeLoader = new ThemeLoader();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_pushButton_clicked()
{
    if(themeLoader->getCurrentTheme()!=ui->comboBox->currentText())
    {
        themeLoader->loadTheme(ui->comboBox->currentText());
        themeLoader->wtiteThemeInFile();
    }
    hide();
    //emit mainWindow();
}

