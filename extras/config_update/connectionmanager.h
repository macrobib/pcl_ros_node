#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QtWebSockets/QWebSocket>
#include <QCoreApplication>

QT_USE_NAMESPACE

class connectionManager: public QObject
{
public:
    connectionManager(const QUrl &url, QObject *parent);
    ~connectionManager();
};

#endif // CONNECTIONMANAGER_H
