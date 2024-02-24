#include "settingdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    SettingDialog dialog;
    dialog.show();
    return a.exec();
}
