#ifndef CALLBACKHANDLER_H
#define CALLBACKHANDLER_H

#include <QObject>
#include <QString>

class CallbackHandler: public QObject
{
    Q_OBJECT
public slots:
    void text1Callback(const QString& input);
    void text2Callback(const QString& input);
    void text3Callback(const QString& input);
    void text4Callback(const QString& input);

    void slider1Callback(double input);
    void slider2Callback(double input);
    void slider3Callback(double input);
    void slider4Callback(double input);

    void button1Callback(const QString& input);
    void button2Callback(const QString& input);
    void button3Callback(const QString& input);
    void button4Callback(const QString& input);

public:
    CallbackHandler(QObject* parent);
    ~CallbackHandler();
};

#endif // CALLBACKHANDLER_H
