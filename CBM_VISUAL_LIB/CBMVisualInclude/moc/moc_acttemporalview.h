/****************************************************************************
** Meta object code from reading C++ file 'acttemporalview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../acttemporalview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acttemporalview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ActTemporalView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   17,   16,   16, 0x0a,
      88,   82,   16,   16, 0x0a,
     143,  128,   16,   16, 0x0a,
     215,  204,   16,   16, 0x0a,
     260,  233,   16,   16, 0x0a,
     300,  288,   16,   16, 0x0a,
     325,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ActTemporalView[] = {
    "ActTemporalView\0\0ts,lineColors\0"
    "setVertLines(std::vector<int>,std::vector<QColor>)\0"
    "aps,t\0drawRaster(std::vector<ct_uint8_t>,int)\0"
    "aps,vmScaled,t\0"
    "drawVmRaster(std::vector<ct_uint8_t>,std::vector<float>,int)\0"
    "blankColor\0drawBlank(QColor)\0"
    "t,percentHeight,pointColor\0"
    "drawPoint(int,float,QColor)\0t,lineColor\0"
    "drawVertLine(int,QColor)\0toggleVisible()\0"
};

void ActTemporalView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ActTemporalView *_t = static_cast<ActTemporalView *>(_o);
        switch (_id) {
        case 0: _t->setVertLines((*reinterpret_cast< std::vector<int>(*)>(_a[1])),(*reinterpret_cast< std::vector<QColor>(*)>(_a[2]))); break;
        case 1: _t->drawRaster((*reinterpret_cast< std::vector<ct_uint8_t>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->drawVmRaster((*reinterpret_cast< std::vector<ct_uint8_t>(*)>(_a[1])),(*reinterpret_cast< std::vector<float>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->drawBlank((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->drawPoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 5: _t->drawVertLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 6: _t->toggleVisible(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ActTemporalView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ActTemporalView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ActTemporalView,
      qt_meta_data_ActTemporalView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ActTemporalView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ActTemporalView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ActTemporalView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ActTemporalView))
        return static_cast<void*>(const_cast< ActTemporalView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ActTemporalView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
