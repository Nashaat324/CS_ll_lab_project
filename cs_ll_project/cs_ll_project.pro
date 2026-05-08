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
    $$PWD/third_party/googletest-main/googletest/src/gtest-all.cc \


HEADERS += \
    ServerLogic/ServerLogic.h \
    ServerLogic/nlohmann/json.hpp \
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


QMAKE_CFLAGS += -Wno-implicit-function-declaration
QMAKE_CXXFLAGS += -Wno-implicit-function-declaration
