#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QtWebSockets/QWebSocket>
#include <QCoreApplication>

QT_USE_NAMESPACE

//Class to provide tls based socket communication to ros configuration node.
class connectionManager: public QObject
{
public:
    connectionManager(const QUrl &url, QObject *parent);
    ~connectionManager();
};

#endif // CONNECTIONMANAGER_H
