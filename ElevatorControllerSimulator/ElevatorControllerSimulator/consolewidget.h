#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#include <QWidget>
#include <QString>

#include "ecs.h"

namespace Ui {
class ConsoleWidget;
}

class ConsoleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConsoleWidget(ECS *ecs, QWidget *parent = nullptr);
    ~ConsoleWidget();

    void log(QString level, QString msg);

public slots:
    void info(QString msg);
    void warn(QString msg);


private:
    Ui::ConsoleWidget *ui;
    ECS *ecs;
};

#endif // CONSOLEWIDGET_H
