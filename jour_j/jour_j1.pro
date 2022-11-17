
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console

CONFIG += c++17
QT += widgets
QT += widgets quickwidgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    event.cpp \
    local.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp

HEADERS += \
    connection.h \
    event.h \
    local.h \
    mainwindow.h \
    smtp.h \
    webaxwidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES +=
