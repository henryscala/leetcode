TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    twosum.h \
    addtwonumbers.h \
    longsubstr.h \
    palindrome.h \
    zigzag.h \
    reversenum.h \
    myatoi.h

