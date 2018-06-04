#include "connectionmanager.h"
#include "ros_config_structs.h"


connectionManager::connectionManager(const QUrl &url, QObject *parent):QObject(parent)
{

}
connectionManager::~connectionManager()
{

}

void connectionManager::sendData(){}
