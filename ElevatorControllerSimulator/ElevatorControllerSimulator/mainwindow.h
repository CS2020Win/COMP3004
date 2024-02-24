#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QFrame>

#include "ecs.h"
#include "elevatorwidget.h"
#include "floorwidget.h"
#include "consolewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void init();

private:
    Ui::MainWindow *ui;

    ECS *ecs;
    ElevatorWidget *elevatorWidget;
    FloorWidget *floorWidget;
    ConsoleWidget *consoleWidget;
    QFrame* line;
    QFrame* line2;
};

#endif // MAINWINDOW_H
