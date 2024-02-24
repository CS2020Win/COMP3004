#include "consolewidget.h"
#include "ui_consolewidget.h"

#include <QDateTime>

ConsoleWidget::ConsoleWidget(ECS *ecs, QWidget *parent) :
    QWidget(parent), ecs(ecs),
    ui(new Ui::ConsoleWidget)
{
    ui->setupUi(this);
}

ConsoleWidget::~ConsoleWidget()
{
    delete ui;
}

void ConsoleWidget::log(QString level, QString msg)
{
    ui->textBrowser->append(QString("[%1] %2 %3").arg(level).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(msg));
}

void ConsoleWidget::info(QString msg)
{
    log("info", msg);
}

void ConsoleWidget::warn(QString msg)
{
    log("warn", msg);
}

