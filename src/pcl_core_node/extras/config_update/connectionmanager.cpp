#include "connectionmanager.h"
#include "ros_config_structs.h"
#include <QDebug>
#include <cstring>


connectionManager::connectionManager(const QUrl &url, quint16 port, QObject *parent):
  QObject(parent), url_(url), debug_enabled_(true), connection_status_(false),
  pWebSocketServer_(new QWebSocketServer(QStringLiteral("Config manager"),
                                         QWebSocketServer::NonSecureMode, this))
{
  if(pWebSocketServer_->listen(QHostAddress::LocalHost, port)){
    if(debug_enabled_)
      qDebug() << "Config server started listening on the port: "<< port;

    connect(pWebSocketServer_, &QWebSocketServer::newConnection, this, &connectionManager::onNewConnection);
    connect(pWebSocketServer_, &QWebSocketServer::closed, this, &connectionManager::closed);
  }
  else{
    qDebug() << "Failed to listen on the given port.";
  }
}

void connectionManager::onNewConnection(){
  QWebSocket* pSocket = pWebSocketServer_->nextPendingConnection();
  if(debug_enabled_)
    qDebug() << "Recieved a new client connection.";
    connect(pSocket, &QWebSocket::textFrameReceived, this, &connectionManager::processTextMessage);
    connect(pSocket, &QWebSocket::binaryFrameReceived, this, &connectionManager::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &connectionManager::socketDisconnected);

    struct CommonMessage data;
    data.type = ePASSTHROUGH;
    data.data.ps.min_z = 1.00;
    data.data.ps.max_z = 2.00;

    char* data_array = new char[sizeof(data)];
    std::memset(data_array, 0, sizeof data);
    std::memcpy(data_array,(char*)&data, sizeof data);
    if(debug_enabled_)
      qDebug() << "Data written of size: " << sizeof data;
//    QByteArray payload(reinterpret_cast<char*>(data));
    pSocket->sendBinaryMessage(data_array);
    clients_.push_back(pSocket);

}

void connectionManager::processBinaryMessage(QByteArray message){

  QWebSocket* pClient = qobject_cast<QWebSocket *>(sender());
  if(debug_enabled_)
    qDebug() << "Binary message recieved.";

}

void connectionManager::processTextMessage(QString message){

  QWebSocket* pClient = qobject_cast<QWebSocket *>(sender());
  if(debug_enabled_)
    qDebug() << "Text message recieved.";

}

void connectionManager::socketDisconnected(){
    if(debug_enabled_)
      qDebug() << "Socket disconnection recieved.";
}

connectionManager::~connectionManager()
{

}

const bool connectionManager::getConnectionStatus() const{
    return connection_status_;
}

void connectionManager::sendData()
{
}

void connectionManager::closed(){

}

