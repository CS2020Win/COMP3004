#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ecs = new ECS(this);

    floorWidget = new FloorWidget(ecs, this);
    elevatorWidget = new ElevatorWidget(ecs, this);
    consoleWidget = new ConsoleWidget(ecs, this);
    line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Plain);

    line2 = new QFrame(this);
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Plain);

    ui->verticalLayout->addWidget(floorWidget);
    ui->verticalLayout->addWidget(line);
    ui->verticalLayout->addWidget(elevatorWidget);
    ui->verticalLayout->addWidget(line2);
    ui->verticalLayout->addWidget(consoleWidget);

    connect(ecs, &ECS::onMessage, consoleWidget, &ConsoleWidget::info);
    connect(floorWidget, &FloorWidget::onMessage, consoleWidget, &ConsoleWidget::info);
    connect(elevatorWidget, &ElevatorWidget::onMessage, consoleWidget, &ConsoleWidget::info);
}
