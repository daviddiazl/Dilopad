QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main/main.cpp \
    main/mainwindow.cpp \
    utilities/meditortexto.cpp \
    utilities/mmodes.cpp \
    utilities/mmenu.cpp

HEADERS += \
    main/mainwindow.h \
    utilities/meditortexto.h \
    utilities/mmodes.h \
    utilities/mmenu.h

FORMS += \
    main/mainwindow.ui \
    utilities/meditortexto.ui \
    utilities/mmodes.ui \
    utilities/mmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
