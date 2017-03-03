#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T19:03:51
#
#-------------------------------------------------

QT       += core gui
QT += gui declarative
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AES
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        base64.c \
        base64_with_file.c \
        aes.c \
        aes_with_file.c


HEADERS  += mainwindow.h \
        base64.h \
        base64_with_file.h \
        aes.h \
        aes_with_file.h



FORMS    += mainwindow.ui
