#include "floorwidget.h"
#include "ui_floorwidget.h"
#include "common.h"

FloorWidget::FloorWidget(ECS *ecs, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloorWidget),
    ecs(ecs),
    floor(nullptr)
{
    ui->setupUi(this);

    for(int i=0;i<Common::floorCount;i++) {
        ui->comboBox->addItem(QString::number(i+1));
    }

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &FloorWidget::floorIndexChanged);

    for(int i=0;i<Common::elevatorCount;i++) {
        Elevator* elevator = ecs->getElevator(i);

        QLabel* nameLabel = new QLabel(this);
        nameLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setText(QString("Elevator %1").arg(i+1));

        QLabel *textLabel = new QLabel(this);
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setText(elevator->toString());

        ui->gridLayout->addWidget(nameLabel, 0, i,1,1);
        ui->gridLayout->addWidget(textLabel, 1, i,1,1);

        connect(elevator, &Elevator::onFloorTextChanged, textLabel, &QLabel::setText);
    }

    ui->pushButton_up->setAutoDefault(false);
    ui->pushButton_down->setAutoDefault(false);
    ui->pushButton_fire->setAutoDefault(false);
    ui->pushButton_power->setAutoDefault(false);

    floorIndexChanged(0);
}

FloorWidget::~FloorWidget()
{
    delete ui;
}

void FloorWidget::floorIndexChanged(int index)
{
    if(floor) {
        disconnect(floor, &Floor::onUpdate, this, &FloorWidget::updateWidget);
    }
    floor = ecs->getFloor(index);
    connect(floor, &Floor::onUpdate, this, &FloorWidget::updateWidget);
    updateWidget();
}

void FloorWidget::updateWidget()
{
    if(floor) {
        if(floor->getButtonUp()->getState()==0) {
            ui->pushButton_up->setStyleSheet(style_default);
        } else {
            ui->pushButton_up->setStyleSheet(style_light);
        }
        if(floor->getButtonDown()->getState()==0) {
            ui->pushButton_down->setStyleSheet(style_default);
        } else {
            ui->pushButton_down->setStyleSheet(style_light);
        }
    }
}

void FloorWidget::on_pushButton_up_clicked()
{
    emit onMessage(QString("Floor %1 pressed Up button").arg(floor->getFloorNumber()+1));
    if(floor->getButtonUp()->getState()==0) {
        ecs->floorRequest(floor->getFloorNumber(), Direction::UP);
        updateWidget();
    }
}


void FloorWidget::on_pushButton_down_clicked()
{
    emit onMessage(QString("Floor %1 pressed Down button").arg(floor->getFloorNumber()+1));
    if(floor->getButtonDown()->getState()==0) {
        ecs->floorRequest(floor->getFloorNumber(), Direction::DOWN);
        updateWidget();
    }
}


void FloorWidget::on_pushButton_fire_clicked()
{
    emit onMessage(QString("Floor %1 pressed Fire button").arg(floor->getFloorNumber()+1));
    ecs->onFireAlarm();
}


void FloorWidget::on_pushButton_power_clicked()
{
    emit onMessage(QString("Floor %1 pressed Power Out button").arg(floor->getFloorNumber()+1));
    ecs->onPowerOut();
}

