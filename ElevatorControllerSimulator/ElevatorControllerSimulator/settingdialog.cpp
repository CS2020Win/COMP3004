#include "settingdialog.h"
#include "ui_settingdialog.h"

#include "common.h"

//int Common::floorCount;
//int Common::elevatorCount;
//int Common::maxWeight;

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}


void SettingDialog::accept() {

    Common::floorCount = ui->floorsSpinBox->value();
    Common::elevatorCount = ui->elevatorsSpinBox->value();
    Common::maxWeight = ui->maxWeightSpinBox->value();

    main = new MainWindow();
    main->show();
    this->hide();
}
