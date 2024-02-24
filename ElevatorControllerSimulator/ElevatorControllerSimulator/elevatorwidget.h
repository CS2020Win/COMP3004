#ifndef ELEVATORWIDGET_H
#define ELEVATORWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "ecs.h"
#include "elevator.h"

namespace Ui {
class ElevatorWidget;
}

class ElevatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ElevatorWidget(ECS *ecs, QWidget *parent = nullptr);
    ~ElevatorWidget();

signals:
    void onMessage(QString message);

public slots:
    void elevatorIndexChanged(int index);
    void updateWidget();
    void floorButtonClick();
    void on_btn_open_click();
    void on_btn_close_click();
    void on_btn_help_click();

private slots:
    void on_spinBox_weight_valueChanged(int arg1);

    void on_checkBox_obstacle_stateChanged(int arg1);

    void timeout();
private:
    Ui::ElevatorWidget *ui;

    Elevator* elevator;
    ECS *ecs;

    QList<QPushButton*> floorButtonList;

    QTimer *m_timer;
};

#endif // ELEVATORWIDGET_H
