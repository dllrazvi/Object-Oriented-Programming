/****************************************************************************
** Meta object code from reading C++ file 'PersonWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PersonWindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PersonWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPersonWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPersonWindowENDCLASS = QtMocHelpers::stringData(
    "PersonWindow",
    "on_showNearbyEventsOnlyCheckbox_toggled",
    "",
    "checked",
    "on_addEventButton_clicked",
    "on_markAttendanceButton_clicked",
    "on_eventsListWidget_itemClicked",
    "QListWidgetItem*",
    "item"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPersonWindowENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[40];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[26];
    char stringdata5[32];
    char stringdata6[32];
    char stringdata7[17];
    char stringdata8[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPersonWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPersonWindowENDCLASS_t qt_meta_stringdata_CLASSPersonWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "PersonWindow"
        QT_MOC_LITERAL(13, 39),  // "on_showNearbyEventsOnlyCheckb..."
        QT_MOC_LITERAL(53, 0),  // ""
        QT_MOC_LITERAL(54, 7),  // "checked"
        QT_MOC_LITERAL(62, 25),  // "on_addEventButton_clicked"
        QT_MOC_LITERAL(88, 31),  // "on_markAttendanceButton_clicked"
        QT_MOC_LITERAL(120, 31),  // "on_eventsListWidget_itemClicked"
        QT_MOC_LITERAL(152, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(169, 4)   // "item"
    },
    "PersonWindow",
    "on_showNearbyEventsOnlyCheckbox_toggled",
    "",
    "checked",
    "on_addEventButton_clicked",
    "on_markAttendanceButton_clicked",
    "on_eventsListWidget_itemClicked",
    "QListWidgetItem*",
    "item"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPersonWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x08,    1 /* Private */,
       4,    0,   41,    2, 0x08,    3 /* Private */,
       5,    0,   42,    2, 0x08,    4 /* Private */,
       6,    1,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject PersonWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSPersonWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPersonWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPersonWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PersonWindow, std::true_type>,
        // method 'on_showNearbyEventsOnlyCheckbox_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_addEventButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_markAttendanceButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_eventsListWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>
    >,
    nullptr
} };

void PersonWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PersonWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_showNearbyEventsOnlyCheckbox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_addEventButton_clicked(); break;
        case 2: _t->on_markAttendanceButton_clicked(); break;
        case 3: _t->on_eventsListWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *PersonWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPersonWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PersonWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
