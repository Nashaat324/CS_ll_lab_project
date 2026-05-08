#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "client.h"
#include "MockNetworkClient.h"

#include <QLineEdit>
#include <QListWidget>
#include <QLabel>

using namespace testing;

TEST(ClientTest, EmptyMessageDoesNotSend)
{
    MockNetworkClient mock;
    EXPECT_CALL(mock, connectToServer(testing::_, testing::_))
        .Times(1);

    Client client(&mock);

    EXPECT_CALL(mock, sendData(_))
        .Times(0);

    client.findChild<QLineEdit*>("type")
        ->setText("");

    client.on_send_clicked();
}

TEST(ClientTest, ValidMessageSendsData)
{
    MockNetworkClient mock;
    EXPECT_CALL(mock, connectToServer(testing::_, testing::_))
        .Times(1);

    Client client(&mock);

    client.setUsername("Yahia");
    client.setTechnician("Ahmed");

    client.findChild<QLineEdit*>("type")
        ->setText("Hello");

    EXPECT_CALL(mock, sendData(_))
        .Times(1);

    client.on_send_clicked();
}

TEST(ClientTest, FakeServerMessageDisplayed)
{
    MockNetworkClient mock;
    EXPECT_CALL(mock, connectToServer(testing::_, testing::_))
        .Times(1);

    Client client(&mock);

    QByteArray fakeReply =
        "Hello from fake server";

    EXPECT_CALL(mock, receiveData())
        .WillOnce(Return(fakeReply));

    client.onReadyRead();

    QListWidget* screen =
        client.findChild<QListWidget*>("screen");

    EXPECT_TRUE(
        screen->item(0)->text()
            .contains("Hello")
        );
}

TEST(ClientTest, TechnicianLabelUpdated)
{
    MockNetworkClient mock;
    EXPECT_CALL(mock, connectToServer(testing::_, testing::_))
        .Times(1);

    Client client(&mock);

    client.setTechnician("Ahmed");

    QLabel* label =
        client.findChild<QLabel*>("label_2");

    EXPECT_TRUE(
        label->text().contains("Ahmed")
        );
}

TEST(ClientTest, InputClearedAfterSending)
{
    MockNetworkClient mock;
    EXPECT_CALL(mock, connectToServer(testing::_, testing::_))
        .Times(1);

    Client client(&mock);

    client.setUsername("Yahia");
    client.setTechnician("Ahmed");

    QLineEdit* input =
        client.findChild<QLineEdit*>("type");

    input->setText("Testing");

    EXPECT_CALL(mock, sendData(_));

    client.on_send_clicked();

    EXPECT_TRUE(input->text().isEmpty());
}
