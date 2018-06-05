#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>
#include <QCoreApplication>
#include <vector>

QT_USE_NAMESPACE

//Class to provide tls based socket communication to ros configuration node.
class connectionManager: public QObject
{

public:
    connectionManager(const QUrl &url, quint16 port, QObject *parent = nullptr);
    ~connectionManager();
    void sendData();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();
    const bool getConnectionStatus() const;

private:
    QWebSocketServer* pWebSocketServer_;
    std::vector<QWebSocket* > clients_;
    QUrl url_;
    bool debug_enabled_;
    bool connection_status_;
};

#endif // CONNECTIONMANAGER_H
