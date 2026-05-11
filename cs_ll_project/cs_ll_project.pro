QT += core gui widgets network

CONFIG += c++20


SOURCES += \
    history.cpp \
    loginpage.cpp \
    main.cpp \
    client.cpp \
    issueticket.cpp \
    FeedbackPage.cpp \
    #test_client.cpp \
    #test_main.cpp

HEADERS += \
    INetworkClient.h \
    MockNetworkClient.h \
    TcpNetworkClient.h \
    client.h \
    history.h \
    issueticket.h \
    FeedbackPage.h \
    loginpage.h

FORMS += \
    client.ui \
    history.ui \
    issueticket.ui \
    FeedbackPage.ui \
    loginpage.ui


win32 {
    LIBS += -lws2_32
}


macx {
    INCLUDEPATH += /opt/homebrew/include
    LIBS += -L/opt/homebrew/lib \
            -lgtest \
            -lgmock \
            -lpthread
}


QMAKE_CFLAGS += -Wno-implicit-function-declaration
QMAKE_CXXFLAGS += -Wno-implicit-function-declaration
