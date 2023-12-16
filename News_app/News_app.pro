#-------------------------------------------------
#
# Project created by QtCreator 2018-03-14T16:04:54
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = News_app
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


SOURCES += \
    allnewstab.cpp \
        main.cpp \
        mainwindow.cpp \
    parser.cpp \
    settingstab.cpp \
    newsitem.cpp \
    tinyxml2.cpp \
    xmlnewsreader.cpp \
    parsednews.cpp

HEADERS += \
    allnewstab.h \
        mainwindow.h \
    parser.h \
    settingstab.h \
    newsitem.h \
    tinyxml2.h \
    xmlnewsreader.h \
    parsednews.h

FORMS += \
    allnewstab.ui \
        mainwindow.ui \
    settingstab.ui \
    newsitem.ui
