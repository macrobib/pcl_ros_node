#include "callbackhandler.h"
#include <QtDebug>

CallbackHandler::CallbackHandler(QObject* parent=0):QObject(parent)
{

}

CallbackHandler::~CallbackHandler()
{

}

void CallbackHandler::button1Callback(const QString& input)
{
  qDebug() << "Button 1 clicked..";
}

void CallbackHandler::button2Callback(const QString& input)
{
  qDebug() << "Button 2 clicked..";
}
void CallbackHandler::button3Callback(const QString& input)
{
  qDebug() << "Button 3 clicked..";
}

void CallbackHandler::button4Callback(const QString& input)
{
  qDebug() << "Button 4 clicked..";
}

void CallbackHandler::slider1Callback(double input)
{
  qDebug() << "Slider 1 callback recieved:  "<< input;
}

void CallbackHandler::slider2Callback(double input)
{
  qDebug() << "Slider 2 callback recieved:  "<< input;
}

void CallbackHandler::slider3Callback(double input)
{
  qDebug() << "Slider 3 callback recieved:  "<< input;
}

void CallbackHandler::slider4Callback(double input)
{
  qDebug() << "Slider 4 callback recieve:  "<< input;
}

void CallbackHandler::text1Callback(const QString &input)
{
  qDebug() << "Textbox 1 callback recieved.  "<< input;
}

void CallbackHandler::text2Callback(const QString &input)
  {
    qDebug() << "Textbox 2 callbac recieved.  "<< input;
  }

void CallbackHandler::text3Callback(const QString &input)
{
  qDebug() << "Textbox 3 callback recieved.  "<< input;
}

void CallbackHandler::text4Callback(const QString &input)
{
  qDebug() << "Textbox 4 callback recieved.  "<< input;
}
