QT       += core gui \
			serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	SerialManager.cpp \
	SerialMonitorWidget.cpp \
	ServoMotor.cpp \
	main.cpp \
	mainwindow.cpp \
	serialcontrol.cpp \
	servocommand.cpp \
	servocontrol.cpp \
	watchdogserial.cpp

HEADERS += \
	SerialManager.h \
	SerialMonitorWidget.h \
	ServoMotor.h \
	SingletonBase.h \
	mainwindow.h \
	serialcontrol.h \
	servocommand.h \
	servocontrol.h \
	watchdogserial.h

FORMS += \
	SerialMonitorWidget.ui \
	mainwindow.ui

VERSION = 1.0.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
