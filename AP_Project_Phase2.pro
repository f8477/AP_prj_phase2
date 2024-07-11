QT       += core gui sql

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
    account.cpp \
    accountClass.cpp \
    comment.cpp \
    company.cpp \
    content.cpp \
    directmessage.cpp \
    job.cpp \
    like.cpp \
    main.cpp \
    mainwindow.cpp \
    newpost.cpp \
    person.cpp \
    post.cpp \
    profileedit.cpp \
    sendpost.cpp \
    signup_login_page/signup_login.cpp \
    timee.cpp

HEADERS += \
    Home_Tab/Home.h \
    Jobs_Tab/Jobs.h \
    Me_Tab/Me.h \
    Messaging_Tab/Messaging.h \
    MyNetwork_Tab/MyNetwork.h \
    account.h \
    accountClass.h \
    comment.h \
    company.h \
    content.h \
    directmessage.h \
    job.h \
    like.h \
    mainwindow.h \
    newpost.h \
    person.h \
    post.h \
    profileedit.h \
    sendpost.h \
    signup_login_page/signup_login.h \
    timee.h

FORMS += \
    Home_Tab/Home.ui \
    Jobs_Tab/Jobs.ui \
    Me_Tab/Me.ui \
    Messaging_Tab/Messaging.ui \
    MyNetwork_Tab/MyNetwork.ui \
    mainwindow.ui \
    newpost.ui \
    profileedit.ui \
    sendpost.ui \
    signup_login_page/signup_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    assets.qrc
