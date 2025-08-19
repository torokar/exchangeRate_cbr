/****************************************************************************
** Meta object code from reading C++ file 'GraphicsDataItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GraphicsDataItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphicsDataItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphicsDataItem_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsDataItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsDataItem_t qt_meta_stringdata_GraphicsDataItem = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GraphicsDataItem"
QT_MOC_LITERAL(1, 17, 14), // "dataItemChange"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "penItemChange"
QT_MOC_LITERAL(4, 47, 11) // "titleChange"

    },
    "GraphicsDataItem\0dataItemChange\0\0"
    "penItemChange\0titleChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsDataItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicsDataItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphicsDataItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataItemChange(); break;
        case 1: _t->penItemChange(); break;
        case 2: _t->titleChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphicsDataItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsDataItem::dataItemChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphicsDataItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsDataItem::penItemChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphicsDataItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsDataItem::titleChange)) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject GraphicsDataItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsObject::staticMetaObject>(),
    qt_meta_stringdata_GraphicsDataItem.data,
    qt_meta_data_GraphicsDataItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GraphicsDataItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsDataItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsDataItem.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsObject::qt_metacast(_clname);
}

int GraphicsDataItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GraphicsDataItem::dataItemChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphicsDataItem::penItemChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GraphicsDataItem::titleChange()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_Graphics2DGraphItem_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graphics2DGraphItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graphics2DGraphItem_t qt_meta_stringdata_Graphics2DGraphItem = {
    {
QT_MOC_LITERAL(0, 0, 19) // "Graphics2DGraphItem"

    },
    "Graphics2DGraphItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graphics2DGraphItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Graphics2DGraphItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Graphics2DGraphItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphicsDataItem::staticMetaObject>(),
    qt_meta_stringdata_Graphics2DGraphItem.data,
    qt_meta_data_Graphics2DGraphItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Graphics2DGraphItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graphics2DGraphItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Graphics2DGraphItem.stringdata0))
        return static_cast<void*>(this);
    return GraphicsDataItem::qt_metacast(_clname);
}

int Graphics2DGraphItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicsDataItem::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Graphics2DHistogramItem_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graphics2DHistogramItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graphics2DHistogramItem_t qt_meta_stringdata_Graphics2DHistogramItem = {
    {
QT_MOC_LITERAL(0, 0, 23) // "Graphics2DHistogramItem"

    },
    "Graphics2DHistogramItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graphics2DHistogramItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Graphics2DHistogramItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Graphics2DHistogramItem::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphicsDataItem::staticMetaObject>(),
    qt_meta_stringdata_Graphics2DHistogramItem.data,
    qt_meta_data_Graphics2DHistogramItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Graphics2DHistogramItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graphics2DHistogramItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Graphics2DHistogramItem.stringdata0))
        return static_cast<void*>(this);
    return GraphicsDataItem::qt_metacast(_clname);
}

int Graphics2DHistogramItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicsDataItem::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
