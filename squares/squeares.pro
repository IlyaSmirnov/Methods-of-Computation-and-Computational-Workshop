TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    complex.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    complex.h

