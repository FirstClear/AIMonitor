/****************************************************************************
** Meta object code from reading C++ file 'AIMonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AIMonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AIMonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AIMonitor_t {
    QByteArrayData data[16];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AIMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AIMonitor_t qt_meta_stringdata_AIMonitor = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AIMonitor"
QT_MOC_LITERAL(1, 10, 8), // "sendFlag"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "flag"
QT_MOC_LITERAL(4, 25, 7), // "operate"
QT_MOC_LITERAL(5, 33, 12), // "complateShow"
QT_MOC_LITERAL(6, 46, 13), // "startRealPlay"
QT_MOC_LITERAL(7, 60, 11), // "updateImage"
QT_MOC_LITERAL(8, 72, 13), // "handleResults"
QT_MOC_LITERAL(9, 86, 5), // "image"
QT_MOC_LITERAL(10, 92, 7), // "channel"
QT_MOC_LITERAL(11, 100, 15), // "updateStatistic"
QT_MOC_LITERAL(12, 116, 10), // "captureNum"
QT_MOC_LITERAL(13, 127, 9), // "violatNum"
QT_MOC_LITERAL(14, 137, 9), // "helmtLess"
QT_MOC_LITERAL(15, 147, 8) // "vestLess"

    },
    "AIMonitor\0sendFlag\0\0flag\0operate\0"
    "complateShow\0startRealPlay\0updateImage\0"
    "handleResults\0image\0channel\0updateStatistic\0"
    "captureNum\0violatNum\0helmtLess\0vestLess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AIMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,
       6,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   59,    2, 0x0a /* Public */,
       8,    2,   62,    2, 0x0a /* Public */,
      11,    4,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,   15,

       0        // eod
};

void AIMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AIMonitor *_t = static_cast<AIMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->operate(); break;
        case 2: _t->complateShow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->startRealPlay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->handleResults((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateStatistic((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AIMonitor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AIMonitor::sendFlag)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AIMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AIMonitor::operate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AIMonitor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AIMonitor::complateShow)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AIMonitor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AIMonitor::startRealPlay)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AIMonitor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AIMonitor.data,
      qt_meta_data_AIMonitor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AIMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AIMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AIMonitor.stringdata0))
        return static_cast<void*>(const_cast< AIMonitor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AIMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AIMonitor::sendFlag(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AIMonitor::operate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AIMonitor::complateShow(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AIMonitor::startRealPlay(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
