/****************************************************************************
** Meta object code from reading C++ file 'tcpfilesender.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../tabwidget/tcpfilesender.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpfilesender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpFileSender_t {
    uint offsetsAndSizes[14];
    char stringdata0[14];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[21];
    char stringdata5[9];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TcpFileSender_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_TcpFileSender_t qt_meta_stringdata_TcpFileSender = {
    {
        QT_MOC_LITERAL(0, 13),  // "TcpFileSender"
        QT_MOC_LITERAL(14, 5),  // "start"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 13),  // "startTransfer"
        QT_MOC_LITERAL(35, 20),  // "updateClientProgress"
        QT_MOC_LITERAL(56, 8),  // "numBytes"
        QT_MOC_LITERAL(65, 8)   // "openFile"
    },
    "TcpFileSender",
    "start",
    "",
    "startTransfer",
    "updateClientProgress",
    "numBytes",
    "openFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpFileSender[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    1,   40,    2, 0x0a,    3 /* Public */,
       6,    0,   43,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,

       0        // eod
};

void TcpFileSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpFileSender *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->startTransfer(); break;
        case 2: _t->updateClientProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 3: _t->openFile(); break;
        default: ;
        }
    }
}

const QMetaObject TcpFileSender::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_TcpFileSender.offsetsAndSizes,
    qt_meta_data_TcpFileSender,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpFileSender_t
, QtPrivate::TypeAndForceComplete<TcpFileSender, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpFileSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpFileSender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpFileSender.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TcpFileSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
