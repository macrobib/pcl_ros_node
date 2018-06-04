/****************************************************************************
** Meta object code from reading C++ file 'callbackhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../config_update/callbackhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callbackhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CallbackHandler_t {
    QByteArrayData data[15];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CallbackHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CallbackHandler_t qt_meta_stringdata_CallbackHandler = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CallbackHandler"
QT_MOC_LITERAL(1, 16, 13), // "text1Callback"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "input"
QT_MOC_LITERAL(4, 37, 13), // "text2Callback"
QT_MOC_LITERAL(5, 51, 13), // "text3Callback"
QT_MOC_LITERAL(6, 65, 13), // "text4Callback"
QT_MOC_LITERAL(7, 79, 15), // "slider1Callback"
QT_MOC_LITERAL(8, 95, 15), // "slider2Callback"
QT_MOC_LITERAL(9, 111, 15), // "slider3Callback"
QT_MOC_LITERAL(10, 127, 15), // "slider4Callback"
QT_MOC_LITERAL(11, 143, 15), // "button1Callback"
QT_MOC_LITERAL(12, 159, 15), // "button2Callback"
QT_MOC_LITERAL(13, 175, 15), // "button3Callback"
QT_MOC_LITERAL(14, 191, 15) // "button4Callback"

    },
    "CallbackHandler\0text1Callback\0\0input\0"
    "text2Callback\0text3Callback\0text4Callback\0"
    "slider1Callback\0slider2Callback\0"
    "slider3Callback\0slider4Callback\0"
    "button1Callback\0button2Callback\0"
    "button3Callback\0button4Callback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CallbackHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       5,    1,   80,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       8,    1,   89,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      10,    1,   95,    2, 0x0a /* Public */,
      11,    1,   98,    2, 0x0a /* Public */,
      12,    1,  101,    2, 0x0a /* Public */,
      13,    1,  104,    2, 0x0a /* Public */,
      14,    1,  107,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void CallbackHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CallbackHandler *_t = static_cast<CallbackHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->text1Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->text2Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->text3Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->text4Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slider1Callback((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->slider2Callback((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slider3Callback((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->slider4Callback((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->button1Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->button2Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->button3Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->button4Callback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CallbackHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CallbackHandler.data,
      qt_meta_data_CallbackHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CallbackHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CallbackHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CallbackHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CallbackHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
