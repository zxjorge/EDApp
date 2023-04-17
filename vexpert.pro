QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bedistinctiveorrelatedlesson.cpp \
    basicquiz.cpp \
    bsod.cpp \
    definition.cpp \
    fillableflag.cpp \
    keepsimplelesson.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    meaningfulsymbolismlesson.cpp \
    noletteringorsealslesson.cpp \
    title.cpp \
    usebasiccolorslesson.cpp

VPATH += box2d/src/
INCLUDEPATH += box2d/include/box2d

HEADERS += \
    bedistinctiveorrelatedlesson.h \
    basicquiz.h \
    bsod.h \
    definition.h \
    fillableflag.h \
    keepsimplelesson.h \
    mainmenu.h \
    mainwindow.h \
    meaningfulsymbolismlesson.h \
    noletteringorsealslesson.h \
    title.h \
    usebasiccolorslesson.h \
    flagconstants.h \

FORMS += \
    bedistinctiveorrelatedlesson.ui \
    basicquiz.ui \
    bsod.ui \
    definition.ui \
    fillableflag.ui \
    keepsimplelesson.ui \
    mainmenu.ui \
    mainwindow.ui \
    meaningfulsymbolismlesson.ui \
    noletteringorsealslesson.ui \
    title.ui \
    usebasiccolorslesson.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
