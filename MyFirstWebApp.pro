QT  += core
QT  -= gui
QT  += network
QT += sql

TARGET = MyFirstWebApp

CONFIG   += console

TEMPLATE = app

SOURCES += src/main.cpp \
    src/requestmapper.cpp \
    src/fileuploadcontroller.cpp \
    src/registercontroller.cpp \
    src/database.cpp

HEADERS += \
    src/requestmapper.h \
    src/fileuploadcontroller.h \
    src/registercontroller.h \
    src/database.h

OTHER_FILES += etc/webapp1.ini \
     docroot/files/hello.html

include(httpserver/httpserver.pri)
