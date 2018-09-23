#-------------------------------------------------
#
# Project created by QtCreator 2018-09-23T20:10:36
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = HandControl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        handcontrol.cpp \
    HandControlModel/handcontrolmodel.cpp \
    HandControlModel/HandCommand/handcommand.cpp \
    HandControlModel/HandCommand/reposytoricommands.cpp \
    HandControlModel/HandCommand/ActionHandControl/actionhandcontrol.cpp \
    HandControlModel/HandCommand/ActionHandControl/iactionhandcontrol.cpp \
    HandControlModel/DataConnector/dataconnector.cpp \
    HandControlModel/DataConnector/idataconnectror.cpp \
    HandControlModel/DataConnector/FileSystemConnector/filejsonconnector.cpp \
    HandControlModel/DataConnector/DeviceConnector/deviceconnector.cpp \
    HandControlModel/DataConnector/FileSystemConnector/ifilesystemconnector.cpp

HEADERS += \
        handcontrol.h \
    HandControlModel/handcontrolmodel.h \
    HandControlModel/HandCommand/handcommand.h \
    HandControlModel/HandCommand/reposytoricommands.h \
    HandControlModel/HandCommand/ActionHandControl/actionhandcontrol.h \
    HandControlModel/HandCommand/ActionHandControl/iactionhandcontrol.h \
    HandControlModel/DataConnector/dataconnector.h \
    HandControlModel/DataConnector/idataconnectror.h \
    HandControlModel/DataConnector/FileSystemConnector/filejsonconnector.h \
    HandControlModel/DataConnector/DeviceConnector/deviceconnector.h \
    HandControlModel/DataConnector/FileSystemConnector/ifilesystemconnector.h

FORMS += \
        handcontrol.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
