QT += core gui widgets network

CONFIG += c++20

SOURCES += \
<<<<<<< HEAD
    client.cpp \
    issueticket.cpp \
    main.cpp \
    mainwindow.cpp \
    server.cpp

HEADERS += \
    client.h \
    issueticket.h \
    mainwindow.h

FORMS += \
    client.ui \
    issueticket.ui \
    mainwindow.ui
=======
    FeedbackPage.cpp \
    main.cpp

HEADERS += \
    FeedbackPage.h

FORMS += \
    FeedbackPage.ui
>>>>>>> remotes/origin/feature/feedbackpage

LIBS += -lws2_32 -lmswsock

INCLUDEPATH += C:/Users/Nour/vcpkg/installed/x64-windows/include

QMAKE_CFLAGS += -Wno-implicit-function-declaration
QMAKE_CXXFLAGS += -Wno-implicit-function-declaration
