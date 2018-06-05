#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <iostream>

#include "callbackhandler.h"
#include "objecthandler.h"
#include "connectionmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()){
         std::cout<<"Root object is empty"<< std::endl;
         return -1;
    }



    QObject* rootObject = engine.rootObjects()[0];
    if(!rootObject)
        return -1;

    QUrl url("127.0.0.1");
    objectHandler handler_(rootObject);
    connectionManager conman(url);


    return app.exec();
}
