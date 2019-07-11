/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[75];
    char stringdata0[2146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 40, 5), // "event"
QT_MOC_LITERAL(5, 46, 21), // "on_openFolder_clicked"
QT_MOC_LITERAL(6, 68, 13), // "openDirectory"
QT_MOC_LITERAL(7, 82, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(8, 106, 35), // "on_mexP_Spreadsheets_upload_c..."
QT_MOC_LITERAL(9, 142, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(10, 164, 24), // "on_POInput_returnPressed"
QT_MOC_LITERAL(11, 189, 30), // "on_mexP_Invoice_upload_clicked"
QT_MOC_LITERAL(12, 220, 28), // "on_mexP_Phyto_upload_clicked"
QT_MOC_LITERAL(13, 249, 34), // "on_mexP_ShipperConf_upload_cl..."
QT_MOC_LITERAL(14, 284, 34), // "on_mexP_CarrierConf_upload_cl..."
QT_MOC_LITERAL(15, 319, 30), // "on_mexP_Passing_upload_clicked"
QT_MOC_LITERAL(16, 350, 31), // "on_mexP_SaleConf_upload_clicked"
QT_MOC_LITERAL(17, 382, 33), // "on_mexP_SignedSale_upload_cli..."
QT_MOC_LITERAL(18, 416, 32), // "on_mexP_Pedimento_upload_clicked"
QT_MOC_LITERAL(19, 449, 33), // "on_mexP_ProduceInv_upload_cli..."
QT_MOC_LITERAL(20, 483, 38), // "on_mexP_Payable_Shipper_uploa..."
QT_MOC_LITERAL(21, 522, 40), // "on_mexP_Payables_Carriers_upl..."
QT_MOC_LITERAL(22, 563, 33), // "on_mexP_Spreadsheets_stateCha..."
QT_MOC_LITERAL(23, 597, 4), // "arg1"
QT_MOC_LITERAL(24, 602, 28), // "on_mexP_Invoice_stateChanged"
QT_MOC_LITERAL(25, 631, 26), // "on_mexP_Phyto_stateChanged"
QT_MOC_LITERAL(26, 658, 32), // "on_mexP_ShipperConf_stateChanged"
QT_MOC_LITERAL(27, 691, 32), // "on_mexP_CarrierConf_stateChanged"
QT_MOC_LITERAL(28, 724, 28), // "on_mexP_Passing_stateChanged"
QT_MOC_LITERAL(29, 753, 29), // "on_mexP_SaleConf_stateChanged"
QT_MOC_LITERAL(30, 783, 31), // "on_mexP_SignedSale_stateChanged"
QT_MOC_LITERAL(31, 815, 30), // "on_mexP_Pedimento_stateChanged"
QT_MOC_LITERAL(32, 846, 31), // "on_mexP_ProduceInv_stateChanged"
QT_MOC_LITERAL(33, 878, 36), // "on_mexP_Payable_Shipper_state..."
QT_MOC_LITERAL(34, 915, 38), // "on_mexP_Payables_Carriers_sta..."
QT_MOC_LITERAL(35, 954, 23), // "on_reloadButton_clicked"
QT_MOC_LITERAL(36, 978, 26), // "on_POInput_editingFinished"
QT_MOC_LITERAL(37, 1005, 25), // "on_ExpInvima_stateChanged"
QT_MOC_LITERAL(38, 1031, 32), // "on_FacturaComercial_stateChanged"
QT_MOC_LITERAL(39, 1064, 30), // "on_ListadeEmpaque_stateChanged"
QT_MOC_LITERAL(40, 1095, 26), // "on_CertOrigin_stateChanged"
QT_MOC_LITERAL(41, 1122, 26), // "on_CaftaNafta_stateChanged"
QT_MOC_LITERAL(42, 1149, 31), // "on_FreightContract_stateChanged"
QT_MOC_LITERAL(43, 1181, 27), // "on_Transloader_stateChanged"
QT_MOC_LITERAL(44, 1209, 22), // "on_Harris_stateChanged"
QT_MOC_LITERAL(45, 1232, 28), // "on_HarrisEmails_stateChanged"
QT_MOC_LITERAL(46, 1261, 26), // "on_CustomerPO_stateChanged"
QT_MOC_LITERAL(47, 1288, 27), // "on_OtherEmails_stateChanged"
QT_MOC_LITERAL(48, 1316, 36), // "on_Payables_Transloader_state..."
QT_MOC_LITERAL(49, 1353, 37), // "on_payables_TruckFreight_stat..."
QT_MOC_LITERAL(50, 1391, 31), // "on_Payables_Harris_stateChanged"
QT_MOC_LITERAL(51, 1423, 41), // "on_Payables_ShipperWarehouse_..."
QT_MOC_LITERAL(52, 1465, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(53, 1497, 5), // "index"
QT_MOC_LITERAL(54, 1503, 24), // "on_receipts_stateChanged"
QT_MOC_LITERAL(55, 1528, 27), // "on_ExpInvima_Upload_clicked"
QT_MOC_LITERAL(56, 1556, 26), // "on_receipts_upload_clicked"
QT_MOC_LITERAL(57, 1583, 34), // "on_FacturaComercial_upload_cl..."
QT_MOC_LITERAL(58, 1618, 32), // "on_ListadeEmpaque_upload_clicked"
QT_MOC_LITERAL(59, 1651, 28), // "on_CertOrigin_upload_clicked"
QT_MOC_LITERAL(60, 1680, 28), // "on_CaftaNafta_upload_clicked"
QT_MOC_LITERAL(61, 1709, 33), // "on_FreightContract_upload_cli..."
QT_MOC_LITERAL(62, 1743, 29), // "on_Transloader_upload_clicked"
QT_MOC_LITERAL(63, 1773, 24), // "on_Harris_upload_clicked"
QT_MOC_LITERAL(64, 1798, 30), // "on_HarrisEmails_upload_clicked"
QT_MOC_LITERAL(65, 1829, 28), // "on_CustomerPO_upload_clicked"
QT_MOC_LITERAL(66, 1858, 29), // "on_OtherEmails_upload_clicked"
QT_MOC_LITERAL(67, 1888, 38), // "on_Payables_Transloader_uploa..."
QT_MOC_LITERAL(68, 1927, 39), // "on_payables_TruckFreight_uplo..."
QT_MOC_LITERAL(69, 1967, 33), // "on_Payables_Harris_upload_cli..."
QT_MOC_LITERAL(70, 2001, 43), // "on_Payables_ShipperWarehouse_..."
QT_MOC_LITERAL(71, 2045, 29), // "on_archiveCheckButton_clicked"
QT_MOC_LITERAL(72, 2075, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(73, 2102, 11), // "QModelIndex"
QT_MOC_LITERAL(74, 2114, 31) // "on_archiveCheckButton_2_clicked"

    },
    "MainWindow\0mouseMoveEvent\0\0QMouseEvent*\0"
    "event\0on_openFolder_clicked\0openDirectory\0"
    "on_actionOpen_triggered\0"
    "on_mexP_Spreadsheets_upload_clicked\0"
    "on_saveButton_clicked\0on_POInput_returnPressed\0"
    "on_mexP_Invoice_upload_clicked\0"
    "on_mexP_Phyto_upload_clicked\0"
    "on_mexP_ShipperConf_upload_clicked\0"
    "on_mexP_CarrierConf_upload_clicked\0"
    "on_mexP_Passing_upload_clicked\0"
    "on_mexP_SaleConf_upload_clicked\0"
    "on_mexP_SignedSale_upload_clicked\0"
    "on_mexP_Pedimento_upload_clicked\0"
    "on_mexP_ProduceInv_upload_clicked\0"
    "on_mexP_Payable_Shipper_upload_clicked\0"
    "on_mexP_Payables_Carriers_upload_clicked\0"
    "on_mexP_Spreadsheets_stateChanged\0"
    "arg1\0on_mexP_Invoice_stateChanged\0"
    "on_mexP_Phyto_stateChanged\0"
    "on_mexP_ShipperConf_stateChanged\0"
    "on_mexP_CarrierConf_stateChanged\0"
    "on_mexP_Passing_stateChanged\0"
    "on_mexP_SaleConf_stateChanged\0"
    "on_mexP_SignedSale_stateChanged\0"
    "on_mexP_Pedimento_stateChanged\0"
    "on_mexP_ProduceInv_stateChanged\0"
    "on_mexP_Payable_Shipper_stateChanged\0"
    "on_mexP_Payables_Carriers_stateChanged\0"
    "on_reloadButton_clicked\0"
    "on_POInput_editingFinished\0"
    "on_ExpInvima_stateChanged\0"
    "on_FacturaComercial_stateChanged\0"
    "on_ListadeEmpaque_stateChanged\0"
    "on_CertOrigin_stateChanged\0"
    "on_CaftaNafta_stateChanged\0"
    "on_FreightContract_stateChanged\0"
    "on_Transloader_stateChanged\0"
    "on_Harris_stateChanged\0"
    "on_HarrisEmails_stateChanged\0"
    "on_CustomerPO_stateChanged\0"
    "on_OtherEmails_stateChanged\0"
    "on_Payables_Transloader_stateChanged\0"
    "on_payables_TruckFreight_stateChanged\0"
    "on_Payables_Harris_stateChanged\0"
    "on_Payables_ShipperWarehouse_stateChanged\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_receipts_stateChanged\0"
    "on_ExpInvima_Upload_clicked\0"
    "on_receipts_upload_clicked\0"
    "on_FacturaComercial_upload_clicked\0"
    "on_ListadeEmpaque_upload_clicked\0"
    "on_CertOrigin_upload_clicked\0"
    "on_CaftaNafta_upload_clicked\0"
    "on_FreightContract_upload_clicked\0"
    "on_Transloader_upload_clicked\0"
    "on_Harris_upload_clicked\0"
    "on_HarrisEmails_upload_clicked\0"
    "on_CustomerPO_upload_clicked\0"
    "on_OtherEmails_upload_clicked\0"
    "on_Payables_Transloader_upload_clicked\0"
    "on_payables_TruckFreight_upload_clicked\0"
    "on_Payables_Harris_upload_clicked\0"
    "on_Payables_ShipperWarehouse_upload_clicked\0"
    "on_archiveCheckButton_clicked\0"
    "on_tableView_doubleClicked\0QModelIndex\0"
    "on_archiveCheckButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      68,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  354,    2, 0x09 /* Protected */,
       5,    0,  357,    2, 0x08 /* Private */,
       6,    1,  358,    2, 0x08 /* Private */,
       7,    0,  361,    2, 0x08 /* Private */,
       8,    0,  362,    2, 0x08 /* Private */,
       9,    0,  363,    2, 0x08 /* Private */,
      10,    0,  364,    2, 0x08 /* Private */,
      11,    0,  365,    2, 0x08 /* Private */,
      12,    0,  366,    2, 0x08 /* Private */,
      13,    0,  367,    2, 0x08 /* Private */,
      14,    0,  368,    2, 0x08 /* Private */,
      15,    0,  369,    2, 0x08 /* Private */,
      16,    0,  370,    2, 0x08 /* Private */,
      17,    0,  371,    2, 0x08 /* Private */,
      18,    0,  372,    2, 0x08 /* Private */,
      19,    0,  373,    2, 0x08 /* Private */,
      20,    0,  374,    2, 0x08 /* Private */,
      21,    0,  375,    2, 0x08 /* Private */,
      22,    1,  376,    2, 0x08 /* Private */,
      24,    1,  379,    2, 0x08 /* Private */,
      25,    1,  382,    2, 0x08 /* Private */,
      26,    1,  385,    2, 0x08 /* Private */,
      27,    1,  388,    2, 0x08 /* Private */,
      28,    1,  391,    2, 0x08 /* Private */,
      29,    1,  394,    2, 0x08 /* Private */,
      30,    1,  397,    2, 0x08 /* Private */,
      31,    1,  400,    2, 0x08 /* Private */,
      32,    1,  403,    2, 0x08 /* Private */,
      33,    1,  406,    2, 0x08 /* Private */,
      34,    1,  409,    2, 0x08 /* Private */,
      35,    0,  412,    2, 0x08 /* Private */,
      36,    0,  413,    2, 0x08 /* Private */,
      37,    1,  414,    2, 0x08 /* Private */,
      38,    1,  417,    2, 0x08 /* Private */,
      39,    1,  420,    2, 0x08 /* Private */,
      40,    1,  423,    2, 0x08 /* Private */,
      41,    1,  426,    2, 0x08 /* Private */,
      42,    1,  429,    2, 0x08 /* Private */,
      43,    1,  432,    2, 0x08 /* Private */,
      44,    1,  435,    2, 0x08 /* Private */,
      45,    1,  438,    2, 0x08 /* Private */,
      46,    1,  441,    2, 0x08 /* Private */,
      47,    1,  444,    2, 0x08 /* Private */,
      48,    1,  447,    2, 0x08 /* Private */,
      49,    1,  450,    2, 0x08 /* Private */,
      50,    1,  453,    2, 0x08 /* Private */,
      51,    1,  456,    2, 0x08 /* Private */,
      52,    1,  459,    2, 0x08 /* Private */,
      54,    1,  462,    2, 0x08 /* Private */,
      55,    0,  465,    2, 0x08 /* Private */,
      56,    0,  466,    2, 0x08 /* Private */,
      57,    0,  467,    2, 0x08 /* Private */,
      58,    0,  468,    2, 0x08 /* Private */,
      59,    0,  469,    2, 0x08 /* Private */,
      60,    0,  470,    2, 0x08 /* Private */,
      61,    0,  471,    2, 0x08 /* Private */,
      62,    0,  472,    2, 0x08 /* Private */,
      63,    0,  473,    2, 0x08 /* Private */,
      64,    0,  474,    2, 0x08 /* Private */,
      65,    0,  475,    2, 0x08 /* Private */,
      66,    0,  476,    2, 0x08 /* Private */,
      67,    0,  477,    2, 0x08 /* Private */,
      68,    0,  478,    2, 0x08 /* Private */,
      69,    0,  479,    2, 0x08 /* Private */,
      70,    0,  480,    2, 0x08 /* Private */,
      71,    0,  481,    2, 0x08 /* Private */,
      72,    1,  482,    2, 0x08 /* Private */,
      74,    0,  485,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 73,   53,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_openFolder_clicked(); break;
        case 2: _t->openDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->on_mexP_Spreadsheets_upload_clicked(); break;
        case 5: _t->on_saveButton_clicked(); break;
        case 6: _t->on_POInput_returnPressed(); break;
        case 7: _t->on_mexP_Invoice_upload_clicked(); break;
        case 8: _t->on_mexP_Phyto_upload_clicked(); break;
        case 9: _t->on_mexP_ShipperConf_upload_clicked(); break;
        case 10: _t->on_mexP_CarrierConf_upload_clicked(); break;
        case 11: _t->on_mexP_Passing_upload_clicked(); break;
        case 12: _t->on_mexP_SaleConf_upload_clicked(); break;
        case 13: _t->on_mexP_SignedSale_upload_clicked(); break;
        case 14: _t->on_mexP_Pedimento_upload_clicked(); break;
        case 15: _t->on_mexP_ProduceInv_upload_clicked(); break;
        case 16: _t->on_mexP_Payable_Shipper_upload_clicked(); break;
        case 17: _t->on_mexP_Payables_Carriers_upload_clicked(); break;
        case 18: _t->on_mexP_Spreadsheets_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_mexP_Invoice_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_mexP_Phyto_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_mexP_ShipperConf_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_mexP_CarrierConf_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_mexP_Passing_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_mexP_SaleConf_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_mexP_SignedSale_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_mexP_Pedimento_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_mexP_ProduceInv_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_mexP_Payable_Shipper_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_mexP_Payables_Carriers_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_reloadButton_clicked(); break;
        case 31: _t->on_POInput_editingFinished(); break;
        case 32: _t->on_ExpInvima_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_FacturaComercial_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_ListadeEmpaque_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_CertOrigin_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_CaftaNafta_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_FreightContract_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_Transloader_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_Harris_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_HarrisEmails_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_CustomerPO_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_OtherEmails_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_Payables_Transloader_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_payables_TruckFreight_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_Payables_Harris_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_Payables_ShipperWarehouse_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_receipts_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_ExpInvima_Upload_clicked(); break;
        case 50: _t->on_receipts_upload_clicked(); break;
        case 51: _t->on_FacturaComercial_upload_clicked(); break;
        case 52: _t->on_ListadeEmpaque_upload_clicked(); break;
        case 53: _t->on_CertOrigin_upload_clicked(); break;
        case 54: _t->on_CaftaNafta_upload_clicked(); break;
        case 55: _t->on_FreightContract_upload_clicked(); break;
        case 56: _t->on_Transloader_upload_clicked(); break;
        case 57: _t->on_Harris_upload_clicked(); break;
        case 58: _t->on_HarrisEmails_upload_clicked(); break;
        case 59: _t->on_CustomerPO_upload_clicked(); break;
        case 60: _t->on_OtherEmails_upload_clicked(); break;
        case 61: _t->on_Payables_Transloader_upload_clicked(); break;
        case 62: _t->on_payables_TruckFreight_upload_clicked(); break;
        case 63: _t->on_Payables_Harris_upload_clicked(); break;
        case 64: _t->on_Payables_ShipperWarehouse_upload_clicked(); break;
        case 65: _t->on_archiveCheckButton_clicked(); break;
        case 66: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 67: _t->on_archiveCheckButton_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 68;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
