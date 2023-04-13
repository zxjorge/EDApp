QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bsod.cpp \
    definition.cpp \
    fillableflag.cpp \
    main.cpp \
    mainwindow.cpp \
    title.cpp

VPATH += box2d/src/
INCLUDEPATH += box2d/include/box2d

HEADERS += \
    bsod.h \
    definition.h \
    fillableflag.h \
    flagConstants.h \
    mainwindow.h \
    title.h

FORMS += \
    bsod.ui \
    definition.ui \
    fillableflag.ui \
    mainwindow.ui \
    title.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
