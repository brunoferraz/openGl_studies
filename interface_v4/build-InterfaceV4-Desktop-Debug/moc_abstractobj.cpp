/****************************************************************************
** Meta object code from reading C++ file 'abstractobj.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InterfaceV4/Lib3d/Display/abstractobj.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractobj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AbstractObj_t {
    QByteArrayData data[6];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AbstractObj_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AbstractObj_t qt_meta_stringdata_AbstractObj = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 12),
QT_MOC_LITERAL(5, 49, 14)
    },
    "AbstractObj\0OnMouseOver\0\0OnMouseOut\0"
    "OnMousePress\0OnMouseRelease\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractObj[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    0,   35,    2, 0x06,
       4,    0,   36,    2, 0x06,
       5,    0,   37,    2, 0x06,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AbstractObj::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractObj *_t = static_cast<AbstractObj *>(_o);
        switch (_id) {
        case 0: _t->OnMouseOver(); break;
        case 1: _t->OnMouseOut(); break;
        case 2: _t->OnMousePress(); break;
        case 3: _t->OnMouseRelease(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractObj::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractObj::OnMouseOver)) {
                *result = 0;
            }
        }
        {
            typedef void (AbstractObj::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractObj::OnMouseOut)) {
                *result = 1;
            }
        }
        {
            typedef void (AbstractObj::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractObj::OnMousePress)) {
                *result = 2;
            }
        }
        {
            typedef void (AbstractObj::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractObj::OnMouseRelease)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AbstractObj::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AbstractObj.data,
      qt_meta_data_AbstractObj,  qt_static_metacall, 0, 0}
};


const QMetaObject *AbstractObj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractObj::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractObj.stringdata))
        return static_cast<void*>(const_cast< AbstractObj*>(this));
    return QObject::qt_metacast(_clname);
}

int AbstractObj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AbstractObj::OnMouseOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AbstractObj::OnMouseOut()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AbstractObj::OnMousePress()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void AbstractObj::OnMouseRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
