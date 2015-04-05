#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T21:35:55
#
#-------------------------------------------------



QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YoutubeDownloader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helper.cpp \
    youtubedownloader.cpp \
    youtubevideoquality.cpp \
    downloader.cpp

HEADERS  += mainwindow.h \
    helper.h \
    youtubedownloader.h \
    youtubevideoquality.h \
    downloader.h

FORMS    += mainwindow.ui \
    downloader.ui

RESOURCES += \
    Res.qrc


LIBS += -LC:/OpenSSL-Win32/lib -lubsec

INCLUDEPATH += C:/OpenSSL-Win32/include

CONFIG += static

win32:RC_FILE = YoutubeDownloader.rc
