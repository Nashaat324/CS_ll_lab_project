QT += core gui widgets network

CONFIG += c++20 console

TEMPLATE = app

SOURCES += \
    ServerLogic/ServerLogic.cpp \
    ServerLogicTest.cpp \
    main_test.cpp \
    history.cpp \
    loginpage.cpp \
    client.cpp \
    issueticket.cpp \
    FeedbackPage.cpp \
    test_client.cpp \
    test_main.cpp \
    $$PWD/third_party/googletest-main/googletest/src/gtest-all.cc

HEADERS += \
    ServerLogic/ServerLogic.h \
    ServerLogic/nlohmann/json.hpp \
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

INCLUDEPATH += \
    $$PWD/third_party/googletest-main/googletest/include \
    $$PWD/third_party/googletest-main/googletest

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
