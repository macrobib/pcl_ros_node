#include "callbackhandler.h"

CallbackHandler::CallbackHandler(QObject* parent=0):QObject(parent)
{

}

CallbackHandler::~CallbackHandler()
{

}

void CallbackHandler::button1Callback(const QString& input){}

void CallbackHandler::button2Callback(const QString& input){}

void CallbackHandler::button3Callback(const QString& input){}

void CallbackHandler::button4Callback(const QString& input){}

void CallbackHandler::slider1Callback(double input){}

void CallbackHandler::slider2Callback(double input){}

void CallbackHandler::slider3Callback(double input){}

void CallbackHandler::slider4Callback(double input){}

void CallbackHandler::text1Callback(const QString &input){}

void CallbackHandler::text2Callback(const QString &input){}

void CallbackHandler::text3Callback(const QString &input){}

void CallbackHandler::text4Callback(const QString &input){}
