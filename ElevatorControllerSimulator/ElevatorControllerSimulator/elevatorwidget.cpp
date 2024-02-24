#include "elevatorwidget.h"
#include "ui_elevatorwidget.h"

ElevatorWidget::ElevatorWidget(ECS *ecs, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElevatorWidget),
    ecs(ecs),
    elevator(nullptr)
{
    ui->setupUi(this);

    for(int i=0;i<Common::elevatorCount;i++) {
        ui->comboBox->addItem(QString::number(i+1));
    }
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &ElevatorWidget::elevatorIndexChanged);

    for(int i=0;i<Common::floorCount;i++) {
        QPushButton *btn = new QPushButton(QString::number(i+1),this);
        btn->setAutoDefault(false);
        floorButtonList.append(btn);

        connect(btn, &QPushButton::clicked, this, &ElevatorWidget::floorButtonClick);

        ui->gridLayout->addWidget(btn, i/2,i%2,1,1);
    }

    {
        int row = Common::floorCount/2+1;
        QPushButton *openBtn = new QPushButton("Open");
        QPushButton *closeBtn = new QPushButton("Close");
        QPushButton *helpBtn = new QPushButton("Help");
        openBtn->setAutoDefault(false);
        closeBtn->setAutoDefault(false);
        helpBtn->setAutoDefault(false);

        connect(openBtn, &QPushButton::clicked, this, &ElevatorWidget::on_btn_open_click);
        connect(closeBtn, &QPushButton::clicked, this, &ElevatorWidget::on_btn_close_click);
        connect(helpBtn, &QPushButton::clicked, this, &ElevatorWidget::on_btn_help_click);

        ui->gridLayout->addWidget(openBtn, row, 0, 1,1);
        ui->gridLayout->addWidget(closeBtn, row, 1, 1,1);
        ui->gridLayout->addWidget(helpBtn, row+1, 0, 1,1);
    }

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &ElevatorWidget::timeout);

    elevatorIndexChanged(0);
}

ElevatorWidget::~ElevatorWidget()
{
    delete ui;
}

void ElevatorWidget::elevatorIndexChanged(int index)
{
    if(elevator) {
        disconnect(elevator, &Elevator::onUpdate, this, &ElevatorWidget::updateWidget);
    }
    elevator = ecs->getElevator(index);
    connect(elevator, &Elevator::onUpdate, this, &ElevatorWidget::updateWidget);
    updateWidget();
}

void ElevatorWidget::updateWidget()
{
    if(elevator) {
        ui->label_floor->setText(elevator->toString());
        ui->label_message->setText(elevator->getMessage());

        for(int i=0;i<floorButtonList.size();i++) {
            QPushButton *btn = floorButtonList.at(i);
            if(elevator->getFloorButtonState(i)==0) {
                btn->setStyleSheet(style_default);
            } else {
                btn->setStyleSheet(style_light);
            }
        }
    }
}

void ElevatorWidget::floorButtonClick()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    int floorNumber = floorButtonList.indexOf(btn);

    ecs->carRequest(elevator->getElevatorNumber(), floorNumber);

    updateWidget();
}

void ElevatorWidget::on_btn_open_click()
{
    emit onMessage(QString("Elevator %1 press OpenDoor button").arg(elevator->getElevatorNumber()+1));
    elevator->openDoor();
}

void ElevatorWidget::on_btn_close_click()
{
    emit onMessage(QString("Elevator %1 press CloseDoor button").arg(elevator->getElevatorNumber()+1));
    elevator->closeDoor();
}

void ElevatorWidget::on_btn_help_click()
{
    emit onMessage(QString("Elevator %1 press Help button").arg(elevator->getElevatorNumber()+1));
    m_timer->start(5*1000);
}

void ElevatorWidget::on_spinBox_weight_valueChanged(int value)
{
    if(value>Common::maxWeight) {
        elevator->overload(true);
    } else {
        elevator->overload(false);
    }
}


void ElevatorWidget::on_checkBox_obstacle_stateChanged(int value)
{
    elevator->setObstacle(value!=0);
}

void ElevatorWidget::timeout()
{
    m_timer->stop();
    emit onMessage(QString("Elevator %1 call 911").arg(elevator->getElevatorNumber()+1));
}

