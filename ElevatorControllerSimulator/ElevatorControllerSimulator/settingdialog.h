#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();

    void accept();

private:
    Ui::SettingDialog *ui;

    MainWindow *main;
};

#endif // SETTINGDIALOG_H
