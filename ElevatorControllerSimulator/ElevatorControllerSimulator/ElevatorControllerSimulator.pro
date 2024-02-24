QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiosystem.cpp \
    bell.cpp \
    button.cpp \
    common.cpp \
    consolewidget.cpp \
    destinationPanel.cpp \
    destinationbutton.cpp \
    display.cpp \
    door.cpp \
    ecs.cpp \
    elevator.cpp \
    elevatorwidget.cpp \
    floor.cpp \
    floorbutton.cpp \
    floorsensor.cpp \
    floorwidget.cpp \
    lightsensor.cpp \
    main.cpp \
    mainwindow.cpp \
    opportunisticstrategy.cpp \
    settingdialog.cpp \
    weightsensor.cpp

HEADERS += \
    audiosystem.h \
    consolewidget.h \
    elevatorwidget.h \
    floorwidget.h \
    lightsensor.h \
    mainwindow.h \
    opportunisticstrategy.h \
    allocationstrategy.h \
    bell.h \
    button.h \
    common.h \
    destinationPanel.h \
    destinationbutton.h \
    display.h \
    door.h \
    ecs.h \
    elevator.h \
    floor.h \
    floorbutton.h \
    floorsensor.h \
    settingdialog.h \
    weightsensor.h

FORMS += \
    consolewidget.ui \
    elevatorwidget.ui \
    floorwidget.ui \
    mainwindow.ui \
    settingdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
