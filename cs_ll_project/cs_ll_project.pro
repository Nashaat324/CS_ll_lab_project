QT += core gui widgets network

CONFIG += c++20 console

TEMPLATE = app

SOURCES += \
    ClientNetwork.cpp \
    ServerLogic/ServerLogic.cpp \
    ServerLogicTest.cpp \
    # main_test.cpp \
    history.cpp \
    loginpage.cpp \
    client.cpp \
    issueticket.cpp \
    FeedbackPage.cpp \
    main.cpp \
    technician.cpp \
    techwindow.cpp \
    test_client.cpp \
    $$PWD/third_party/googletest-main/googletest/src/gtest-all.cc \
    $$PWD/third_party/googletest-main/googlemock/src/gmock-all.cc

HEADERS += \
    ClientNetwork.h \
    ServerLogic/ServerLogic.h \
    ServerLogic/nlohmann/json.hpp \
    INetworkClient.h \
    MockNetworkClient.h \
    SharedStructures.h \
    TcpNetworkClient.h \
    client.h \
    history.h \
    issueticket.h \
    FeedbackPage.h \
    loginpage.h \
    technician.h \
    techwindow.h

FORMS += \
    client.ui \
    history.ui \
    issueticket.ui \
    FeedbackPage.ui \
    loginpage.ui \
    technician.ui \
    techwindow.ui


INCLUDEPATH += \
    $$PWD/third_party/googletest-main/googletest/include \
    $$PWD/third_party/googletest-main/googletest \
    $$PWD/third_party/googletest-main/googlemock/include \
    $$PWD/third_party/googletest-main/googlemock

win32 {
    LIBS += -lws2_32
}

macx {
    INCLUDEPATH += /opt/homebrew/include
    LIBS += -L/opt/homebrew/lib \
            # -lgtest \
            # -lgmock \
            -lpthread
}

QMAKE_CFLAGS += -Wno-implicit-function-declaration
QMAKE_CXXFLAGS += -Wno-implicit-function-declaration
