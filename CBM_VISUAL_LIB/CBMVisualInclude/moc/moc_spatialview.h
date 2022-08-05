/****************************************************************************
** Meta object code from reading C++ file 'spatialview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spatialview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spatialview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SpatialView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      61,   13,   12,   12, 0x0a,
     132,  120,   12,   12, 0x0a,
     159,   12,   12,   12, 0x0a,
     187,  171,   12,   12, 0x0a,
     230,  205,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SpatialView[] = {
    "SpatialView\0\0"
    "dispGridX,dispGridY,cellInds,dispSize,dispColor\0"
    "updateView(uint,uint,std::vector<ct_uint32_t>,uint,QColor)\0"
    "windowTitle\0updateWindowTitle(QString)\0"
    "blankView()\0backgroundColor\0"
    "blankView(QColor)\0windowWidth,windowHeight\0"
    "updateWindowSize(uint,uint)\0"
};

void SpatialView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SpatialView *_t = static_cast<SpatialView *>(_o);
        switch (_id) {
        case 0: _t->updateView((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< std::vector<ct_uint32_t>(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< QColor(*)>(_a[5]))); break;
        case 1: _t->updateWindowTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->blankView(); break;
        case 3: _t->blankView((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->updateWindowSize((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SpatialView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SpatialView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SpatialView,
      qt_meta_data_SpatialView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpatialView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpatialView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpatialView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpatialView))
        return static_cast<void*>(const_cast< SpatialView*>(this));
    return QObject::qt_metacast(_clname);
}

int SpatialView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
