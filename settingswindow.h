#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "themeloader.h"
#include <QDialog>
#include <QDebug>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_pushButton_clicked();

signals:
    void mainWindow();

private:
    Ui::SettingsWindow *ui;
    ThemeLoader *themeLoader;
};

#endif // SETTINGSWINDOW_H
