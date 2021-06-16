QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buy.cpp \
    cart.cpp \
    commodity.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    managecommodity.cpp \
    manageuser.cpp \
    order.cpp \
    register.cpp \
    user.cpp \
    warning.cpp

HEADERS += \
    buy.h \
    cart.h \
    commodity.h \
    login.h \
    mainwindow.h \
    managecommodity.h \
    manageuser.h \
    order.h \
    register.h \
    user.h \
    warning.h

FORMS += \
    buy.ui \
    cart.ui \
    login.ui \
    mainwindow.ui \
    managecommodity.ui \
    manageuser.ui \
    register.ui \
    warning.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
