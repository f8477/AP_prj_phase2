QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Home_Tab/Home.cpp \
    Jobs_Tab/Jobs.cpp \
    Me_Tab/Me.cpp \
    Messaging_Tab/Messaging.cpp \
    MyNetwork_Tab/MyNetwork.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Home_Tab/Home.h \
    Jobs_Tab/Jobs.h \
    Me_Tab/Me.h \
    Messaging_Tab/Messaging.h \
    MyNetwork_Tab/MyNetwork.h \
    mainwindow.h

FORMS += \
    Home_Tab/Home.ui \
    Jobs_Tab/Jobs.ui \
    Me_Tab/Me.ui \
    Messaging_Tab/Messaging.ui \
    MyNetwork_Tab/MyNetwork.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    assets.qrc
