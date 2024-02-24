#ifndef FLOORWIDGET_H
#define FLOORWIDGET_H

#include <QWidget>

#include "ecs.h"
#include "floor.h"

namespace Ui {
class FloorWidget;
}

class FloorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FloorWidget(ECS *ecs, QWidget *parent = nullptr);
    ~FloorWidget();

signals:
    void onMessage(QString message);

private slots:
    void floorIndexChanged(int index);
    void updateWidget();

    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_fire_clicked();

    void on_pushButton_power_clicked();

private:
    Ui::FloorWidget *ui;

    Floor* floor;

    ECS *ecs;
};

#endif // FLOORWIDGET_H
