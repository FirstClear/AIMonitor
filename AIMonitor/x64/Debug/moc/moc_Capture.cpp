/****************************************************************************
** Meta object code from reading C++ file 'Capture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Capture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Capture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Capture_t {
    QByteArrayData data[14];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Capture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Capture_t qt_meta_stringdata_Capture = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Capture"
QT_MOC_LITERAL(1, 8, 11), // "resultReady"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "sendImage"
QT_MOC_LITERAL(4, 31, 5), // "image"
QT_MOC_LITERAL(5, 37, 7), // "channel"
QT_MOC_LITERAL(6, 45, 13), // "sendStatistic"
QT_MOC_LITERAL(7, 59, 10), // "captureNum"
QT_MOC_LITERAL(8, 70, 9), // "violatNum"
QT_MOC_LITERAL(9, 80, 9), // "helmtLess"
QT_MOC_LITERAL(10, 90, 8), // "vestLess"
QT_MOC_LITERAL(11, 99, 3), // "run"
QT_MOC_LITERAL(12, 103, 10), // "changeLock"
QT_MOC_LITERAL(13, 114, 4) // "lock"

    },
    "Capture\0resultReady\0\0sendImage\0image\0"
    "channel\0sendStatistic\0captureNum\0"
    "violatNum\0helmtLess\0vestLess\0run\0"
    "changeLock\0lock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Capture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,
       6,    4,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   54,    2, 0x0a /* Public */,
      12,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void Capture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Capture *_t = static_cast<Capture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resultReady(); break;
        case 1: _t->sendImage((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendStatistic((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->run(); break;
        case 4: _t->changeLock((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Capture::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Capture::resultReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Capture::*_t)(QPixmap , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Capture::sendImage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Capture::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Capture::sendStatistic)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Capture::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Capture.data,
      qt_meta_data_Capture,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Capture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Capture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Capture.stringdata0))
        return static_cast<void*>(const_cast< Capture*>(this));
    return QThread::qt_metacast(_clname);
}

int Capture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Capture::resultReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Capture::sendImage(QPixmap _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Capture::sendStatistic(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
