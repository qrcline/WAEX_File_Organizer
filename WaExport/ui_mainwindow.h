/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionOpen;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *createFile;
    QComboBox *comboBox;
    QTextEdit *notesArea;
    QPushButton *saveButton;
    QLineEdit *POInput;
    QLabel *label_2;
    QPushButton *openFolder;
    QLabel *WAEX_logo;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *PoLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *mexP_Payable_Shipper_upload;
    QLabel *noticeSaleConf;
    QLabel *noticeProduceInv;
    QPushButton *mexP_Payables_Carriers_upload;
    QLabel *noticeSpreadsheets;
    QLabel *noticeShipperConf;
    QCheckBox *mexP_SignedSale;
    QLabel *label_4;
    QPushButton *mexP_Passing_upload;
    QLabel *noticePayableShipper;
    QLabel *noticePhyto;
    QPushButton *mexP_SignedSale_upload;
    QPushButton *mexP_ShipperConf_upload;
    QPushButton *mexP_SaleConf_upload;
    QLabel *noticeCarrierConf;
    QCheckBox *mexP_SaleConf;
    QCheckBox *mexP_Passing;
    QCheckBox *mexP_Payables_Carriers;
    QCheckBox *mexP_ProduceInv;
    QPushButton *mexP_Spreadsheets_upload;
    QLabel *noticeSignedSaleConf;
    QLabel *noticePedimento;
    QCheckBox *mexP_Phyto;
    QCheckBox *mexP_ShipperConf;
    QPushButton *mexP_ProduceInv_upload;
    QCheckBox *mexP_Pedimento;
    QCheckBox *mexP_Invoice;
    QCheckBox *mexP_Payable_Shipper;
    QPushButton *mexP_Invoice_upload;
    QPushButton *mexP_CarrierConf_upload;
    QLabel *noticeInvoice;
    QLabel *noticePayableCarriers;
    QPushButton *mexP_Pedimento_upload;
    QCheckBox *mexP_CarrierConf;
    QCheckBox *mexP_Spreadsheets;
    QLabel *noticePassing;
    QPushButton *mexP_Phyto_upload;
    QCheckBox *receipts;
    QPushButton *receipts_upload;
    QLabel *receipts_notice;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QCheckBox *HarrisEmails;
    QLabel *CertOrigin_notice;
    QPushButton *FreightContract_upload;
    QCheckBox *payables_TruckFreight;
    QPushButton *OtherEmails_upload;
    QCheckBox *ExpInvima;
    QCheckBox *FacturaComercial;
    QCheckBox *Payables_Harris;
    QLabel *Transloader_notice;
    QPushButton *CertOrigin_upload;
    QPushButton *Payables_ShipperWarehouse_upload;
    QCheckBox *Payables_ShipperWarehouse;
    QPushButton *Payables_Harris_upload;
    QCheckBox *CertOrigin;
    QPushButton *ExpInvima_Upload;
    QLabel *Payables_Transloader_notice;
    QLabel *Payables_Harris_notice;
    QPushButton *Transloader_upload;
    QCheckBox *CustomerPO;
    QPushButton *Payables_Transloader_upload;
    QPushButton *HarrisEmails_upload;
    QLabel *payables_TruckFreight_notice;
    QLabel *ExpInvima_notice;
    QLabel *CustomerPO_notice;
    QLabel *CaftaNafta_notice;
    QPushButton *payables_TruckFreight_upload;
    QLabel *label_5;
    QCheckBox *FreightContract;
    QLabel *HarrisEmails_notice;
    QCheckBox *OtherEmails;
    QLabel *ListadeEmpaque_notice;
    QLabel *FacturaComercial_notice;
    QPushButton *FacturaComercial_upload;
    QLabel *Payables_ShipperWarehouse_notice;
    QCheckBox *Harris;
    QCheckBox *Payables_Transloader;
    QCheckBox *Transloader;
    QCheckBox *CaftaNafta;
    QPushButton *CustomerPO_upload;
    QCheckBox *ListadeEmpaque;
    QPushButton *CaftaNafta_upload;
    QLabel *OtherEmails_notice;
    QPushButton *Harris_upload;
    QLabel *Harris_notice;
    QLabel *FreightContract_notice;
    QPushButton *ListadeEmpaque_upload;
    QCommandLinkButton *reloadButton;
    QProgressBar *progressBar_save_createFile;
    QWidget *runArchiveCheck;
    QLabel *WAEX_logo_2;
    QLabel *workingDirectory;
    QLabel *label_3;
    QPushButton *archiveCheckButton;
    QTableView *tableView;
    QLabel *label_6;
    QProgressBar *archivePBar;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLabel *workingDirectory_2;
    QLabel *label_8;
    QLabel *workingDirectory_3;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1198, 638);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 1181, 581));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setMovable(false);
        createFile = new QWidget();
        createFile->setObjectName(QString::fromUtf8("createFile"));
        comboBox = new QComboBox(createFile);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 70, 111, 22));
        comboBox->setFont(font);
        notesArea = new QTextEdit(createFile);
        notesArea->setObjectName(QString::fromUtf8("notesArea"));
        notesArea->setGeometry(QRect(690, 240, 461, 241));
        saveButton = new QPushButton(createFile);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(1050, 490, 101, 31));
        POInput = new QLineEdit(createFile);
        POInput->setObjectName(QString::fromUtf8("POInput"));
        POInput->setGeometry(QRect(30, 40, 113, 21));
        POInput->setFont(font);
        label_2 = new QLabel(createFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 47, 13));
        label_2->setFont(font);
        openFolder = new QPushButton(createFile);
        openFolder->setObjectName(QString::fromUtf8("openFolder"));
        openFolder->setGeometry(QRect(160, 40, 80, 21));
        WAEX_logo = new QLabel(createFile);
        WAEX_logo->setObjectName(QString::fromUtf8("WAEX_logo"));
        WAEX_logo->setGeometry(QRect(855, 5, 321, 111));
        WAEX_logo->setScaledContents(true);
        layoutWidget = new QWidget(createFile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(690, 220, 161, 18));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        PoLabel = new QLabel(layoutWidget);
        PoLabel->setObjectName(QString::fromUtf8("PoLabel"));

        horizontalLayout->addWidget(PoLabel);

        gridLayoutWidget = new QWidget(createFile);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 110, 301, 408));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mexP_Payable_Shipper_upload = new QPushButton(gridLayoutWidget);
        mexP_Payable_Shipper_upload->setObjectName(QString::fromUtf8("mexP_Payable_Shipper_upload"));

        gridLayout->addWidget(mexP_Payable_Shipper_upload, 11, 1, 1, 1);

        noticeSaleConf = new QLabel(gridLayoutWidget);
        noticeSaleConf->setObjectName(QString::fromUtf8("noticeSaleConf"));

        gridLayout->addWidget(noticeSaleConf, 7, 2, 1, 1);

        noticeProduceInv = new QLabel(gridLayoutWidget);
        noticeProduceInv->setObjectName(QString::fromUtf8("noticeProduceInv"));

        gridLayout->addWidget(noticeProduceInv, 10, 2, 1, 1);

        mexP_Payables_Carriers_upload = new QPushButton(gridLayoutWidget);
        mexP_Payables_Carriers_upload->setObjectName(QString::fromUtf8("mexP_Payables_Carriers_upload"));
        mexP_Payables_Carriers_upload->setEnabled(true);

        gridLayout->addWidget(mexP_Payables_Carriers_upload, 17, 1, 1, 1);

        noticeSpreadsheets = new QLabel(gridLayoutWidget);
        noticeSpreadsheets->setObjectName(QString::fromUtf8("noticeSpreadsheets"));

        gridLayout->addWidget(noticeSpreadsheets, 1, 2, 1, 1);

        noticeShipperConf = new QLabel(gridLayoutWidget);
        noticeShipperConf->setObjectName(QString::fromUtf8("noticeShipperConf"));

        gridLayout->addWidget(noticeShipperConf, 4, 2, 1, 1);

        mexP_SignedSale = new QCheckBox(gridLayoutWidget);
        mexP_SignedSale->setObjectName(QString::fromUtf8("mexP_SignedSale"));
        mexP_SignedSale->setFont(font);
        mexP_SignedSale->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_SignedSale->setChecked(true);

        gridLayout->addWidget(mexP_SignedSale, 8, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        mexP_Passing_upload = new QPushButton(gridLayoutWidget);
        mexP_Passing_upload->setObjectName(QString::fromUtf8("mexP_Passing_upload"));

        gridLayout->addWidget(mexP_Passing_upload, 6, 1, 1, 1);

        noticePayableShipper = new QLabel(gridLayoutWidget);
        noticePayableShipper->setObjectName(QString::fromUtf8("noticePayableShipper"));

        gridLayout->addWidget(noticePayableShipper, 11, 2, 1, 1);

        noticePhyto = new QLabel(gridLayoutWidget);
        noticePhyto->setObjectName(QString::fromUtf8("noticePhyto"));

        gridLayout->addWidget(noticePhyto, 3, 2, 1, 1);

        mexP_SignedSale_upload = new QPushButton(gridLayoutWidget);
        mexP_SignedSale_upload->setObjectName(QString::fromUtf8("mexP_SignedSale_upload"));

        gridLayout->addWidget(mexP_SignedSale_upload, 8, 1, 1, 1);

        mexP_ShipperConf_upload = new QPushButton(gridLayoutWidget);
        mexP_ShipperConf_upload->setObjectName(QString::fromUtf8("mexP_ShipperConf_upload"));

        gridLayout->addWidget(mexP_ShipperConf_upload, 4, 1, 1, 1);

        mexP_SaleConf_upload = new QPushButton(gridLayoutWidget);
        mexP_SaleConf_upload->setObjectName(QString::fromUtf8("mexP_SaleConf_upload"));

        gridLayout->addWidget(mexP_SaleConf_upload, 7, 1, 1, 1);

        noticeCarrierConf = new QLabel(gridLayoutWidget);
        noticeCarrierConf->setObjectName(QString::fromUtf8("noticeCarrierConf"));

        gridLayout->addWidget(noticeCarrierConf, 5, 2, 1, 1);

        mexP_SaleConf = new QCheckBox(gridLayoutWidget);
        mexP_SaleConf->setObjectName(QString::fromUtf8("mexP_SaleConf"));
        mexP_SaleConf->setFont(font);
        mexP_SaleConf->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_SaleConf->setChecked(true);

        gridLayout->addWidget(mexP_SaleConf, 7, 0, 1, 1);

        mexP_Passing = new QCheckBox(gridLayoutWidget);
        mexP_Passing->setObjectName(QString::fromUtf8("mexP_Passing"));
        mexP_Passing->setFont(font);
        mexP_Passing->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Passing->setChecked(true);

        gridLayout->addWidget(mexP_Passing, 6, 0, 1, 1);

        mexP_Payables_Carriers = new QCheckBox(gridLayoutWidget);
        mexP_Payables_Carriers->setObjectName(QString::fromUtf8("mexP_Payables_Carriers"));
        mexP_Payables_Carriers->setFont(font);
        mexP_Payables_Carriers->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Payables_Carriers->setChecked(true);

        gridLayout->addWidget(mexP_Payables_Carriers, 17, 0, 1, 1);

        mexP_ProduceInv = new QCheckBox(gridLayoutWidget);
        mexP_ProduceInv->setObjectName(QString::fromUtf8("mexP_ProduceInv"));
        mexP_ProduceInv->setFont(font);
        mexP_ProduceInv->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_ProduceInv->setChecked(true);

        gridLayout->addWidget(mexP_ProduceInv, 10, 0, 1, 1);

        mexP_Spreadsheets_upload = new QPushButton(gridLayoutWidget);
        mexP_Spreadsheets_upload->setObjectName(QString::fromUtf8("mexP_Spreadsheets_upload"));

        gridLayout->addWidget(mexP_Spreadsheets_upload, 1, 1, 1, 1);

        noticeSignedSaleConf = new QLabel(gridLayoutWidget);
        noticeSignedSaleConf->setObjectName(QString::fromUtf8("noticeSignedSaleConf"));

        gridLayout->addWidget(noticeSignedSaleConf, 8, 2, 1, 1);

        noticePedimento = new QLabel(gridLayoutWidget);
        noticePedimento->setObjectName(QString::fromUtf8("noticePedimento"));

        gridLayout->addWidget(noticePedimento, 9, 2, 1, 1);

        mexP_Phyto = new QCheckBox(gridLayoutWidget);
        mexP_Phyto->setObjectName(QString::fromUtf8("mexP_Phyto"));
        mexP_Phyto->setFont(font);
        mexP_Phyto->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Phyto->setChecked(true);

        gridLayout->addWidget(mexP_Phyto, 3, 0, 1, 1);

        mexP_ShipperConf = new QCheckBox(gridLayoutWidget);
        mexP_ShipperConf->setObjectName(QString::fromUtf8("mexP_ShipperConf"));
        mexP_ShipperConf->setFont(font);
        mexP_ShipperConf->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_ShipperConf->setChecked(true);

        gridLayout->addWidget(mexP_ShipperConf, 4, 0, 1, 1);

        mexP_ProduceInv_upload = new QPushButton(gridLayoutWidget);
        mexP_ProduceInv_upload->setObjectName(QString::fromUtf8("mexP_ProduceInv_upload"));

        gridLayout->addWidget(mexP_ProduceInv_upload, 10, 1, 1, 1);

        mexP_Pedimento = new QCheckBox(gridLayoutWidget);
        mexP_Pedimento->setObjectName(QString::fromUtf8("mexP_Pedimento"));
        mexP_Pedimento->setFont(font);
        mexP_Pedimento->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Pedimento->setChecked(true);

        gridLayout->addWidget(mexP_Pedimento, 9, 0, 1, 1);

        mexP_Invoice = new QCheckBox(gridLayoutWidget);
        mexP_Invoice->setObjectName(QString::fromUtf8("mexP_Invoice"));
        mexP_Invoice->setFont(font);
        mexP_Invoice->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Invoice->setChecked(true);

        gridLayout->addWidget(mexP_Invoice, 2, 0, 1, 1);

        mexP_Payable_Shipper = new QCheckBox(gridLayoutWidget);
        mexP_Payable_Shipper->setObjectName(QString::fromUtf8("mexP_Payable_Shipper"));
        mexP_Payable_Shipper->setFont(font);
        mexP_Payable_Shipper->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Payable_Shipper->setChecked(true);

        gridLayout->addWidget(mexP_Payable_Shipper, 11, 0, 1, 1);

        mexP_Invoice_upload = new QPushButton(gridLayoutWidget);
        mexP_Invoice_upload->setObjectName(QString::fromUtf8("mexP_Invoice_upload"));

        gridLayout->addWidget(mexP_Invoice_upload, 2, 1, 1, 1);

        mexP_CarrierConf_upload = new QPushButton(gridLayoutWidget);
        mexP_CarrierConf_upload->setObjectName(QString::fromUtf8("mexP_CarrierConf_upload"));

        gridLayout->addWidget(mexP_CarrierConf_upload, 5, 1, 1, 1);

        noticeInvoice = new QLabel(gridLayoutWidget);
        noticeInvoice->setObjectName(QString::fromUtf8("noticeInvoice"));

        gridLayout->addWidget(noticeInvoice, 2, 2, 1, 1);

        noticePayableCarriers = new QLabel(gridLayoutWidget);
        noticePayableCarriers->setObjectName(QString::fromUtf8("noticePayableCarriers"));

        gridLayout->addWidget(noticePayableCarriers, 17, 2, 1, 1);

        mexP_Pedimento_upload = new QPushButton(gridLayoutWidget);
        mexP_Pedimento_upload->setObjectName(QString::fromUtf8("mexP_Pedimento_upload"));

        gridLayout->addWidget(mexP_Pedimento_upload, 9, 1, 1, 1);

        mexP_CarrierConf = new QCheckBox(gridLayoutWidget);
        mexP_CarrierConf->setObjectName(QString::fromUtf8("mexP_CarrierConf"));
        mexP_CarrierConf->setFont(font);
        mexP_CarrierConf->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_CarrierConf->setChecked(true);

        gridLayout->addWidget(mexP_CarrierConf, 5, 0, 1, 1);

        mexP_Spreadsheets = new QCheckBox(gridLayoutWidget);
        mexP_Spreadsheets->setObjectName(QString::fromUtf8("mexP_Spreadsheets"));
        mexP_Spreadsheets->setFont(font);
        mexP_Spreadsheets->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Spreadsheets->setChecked(true);

        gridLayout->addWidget(mexP_Spreadsheets, 1, 0, 1, 1);

        noticePassing = new QLabel(gridLayoutWidget);
        noticePassing->setObjectName(QString::fromUtf8("noticePassing"));

        gridLayout->addWidget(noticePassing, 6, 2, 1, 1);

        mexP_Phyto_upload = new QPushButton(gridLayoutWidget);
        mexP_Phyto_upload->setObjectName(QString::fromUtf8("mexP_Phyto_upload"));

        gridLayout->addWidget(mexP_Phyto_upload, 3, 1, 1, 1);

        receipts = new QCheckBox(gridLayoutWidget);
        receipts->setObjectName(QString::fromUtf8("receipts"));
        receipts->setFont(font);
        receipts->setCursor(QCursor(Qt::PointingHandCursor));
        receipts->setChecked(true);

        gridLayout->addWidget(receipts, 18, 0, 1, 1);

        receipts_upload = new QPushButton(gridLayoutWidget);
        receipts_upload->setObjectName(QString::fromUtf8("receipts_upload"));
        receipts_upload->setEnabled(true);

        gridLayout->addWidget(receipts_upload, 18, 1, 1, 1);

        receipts_notice = new QLabel(gridLayoutWidget);
        receipts_notice->setObjectName(QString::fromUtf8("receipts_notice"));

        gridLayout->addWidget(receipts_notice, 18, 2, 1, 1);

        gridLayoutWidget_2 = new QWidget(createFile);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(310, 60, 347, 471));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        HarrisEmails = new QCheckBox(gridLayoutWidget_2);
        HarrisEmails->setObjectName(QString::fromUtf8("HarrisEmails"));
        HarrisEmails->setFont(font);
        HarrisEmails->setCursor(QCursor(Qt::PointingHandCursor));
        HarrisEmails->setChecked(true);

        gridLayout_2->addWidget(HarrisEmails, 9, 0, 1, 1);

        CertOrigin_notice = new QLabel(gridLayoutWidget_2);
        CertOrigin_notice->setObjectName(QString::fromUtf8("CertOrigin_notice"));

        gridLayout_2->addWidget(CertOrigin_notice, 4, 2, 1, 1);

        FreightContract_upload = new QPushButton(gridLayoutWidget_2);
        FreightContract_upload->setObjectName(QString::fromUtf8("FreightContract_upload"));

        gridLayout_2->addWidget(FreightContract_upload, 6, 1, 1, 1);

        payables_TruckFreight = new QCheckBox(gridLayoutWidget_2);
        payables_TruckFreight->setObjectName(QString::fromUtf8("payables_TruckFreight"));
        payables_TruckFreight->setFont(font);
        payables_TruckFreight->setCursor(QCursor(Qt::PointingHandCursor));
        payables_TruckFreight->setChecked(true);

        gridLayout_2->addWidget(payables_TruckFreight, 18, 0, 1, 1);

        OtherEmails_upload = new QPushButton(gridLayoutWidget_2);
        OtherEmails_upload->setObjectName(QString::fromUtf8("OtherEmails_upload"));

        gridLayout_2->addWidget(OtherEmails_upload, 11, 1, 1, 1);

        ExpInvima = new QCheckBox(gridLayoutWidget_2);
        ExpInvima->setObjectName(QString::fromUtf8("ExpInvima"));
        ExpInvima->setFont(font);
        ExpInvima->setCursor(QCursor(Qt::PointingHandCursor));
        ExpInvima->setChecked(true);

        gridLayout_2->addWidget(ExpInvima, 1, 0, 1, 1);

        FacturaComercial = new QCheckBox(gridLayoutWidget_2);
        FacturaComercial->setObjectName(QString::fromUtf8("FacturaComercial"));
        FacturaComercial->setFont(font);
        FacturaComercial->setCursor(QCursor(Qt::PointingHandCursor));
        FacturaComercial->setChecked(true);

        gridLayout_2->addWidget(FacturaComercial, 2, 0, 1, 1);

        Payables_Harris = new QCheckBox(gridLayoutWidget_2);
        Payables_Harris->setObjectName(QString::fromUtf8("Payables_Harris"));
        Payables_Harris->setFont(font);
        Payables_Harris->setCursor(QCursor(Qt::PointingHandCursor));
        Payables_Harris->setChecked(true);

        gridLayout_2->addWidget(Payables_Harris, 19, 0, 1, 1);

        Transloader_notice = new QLabel(gridLayoutWidget_2);
        Transloader_notice->setObjectName(QString::fromUtf8("Transloader_notice"));

        gridLayout_2->addWidget(Transloader_notice, 7, 2, 1, 1);

        CertOrigin_upload = new QPushButton(gridLayoutWidget_2);
        CertOrigin_upload->setObjectName(QString::fromUtf8("CertOrigin_upload"));

        gridLayout_2->addWidget(CertOrigin_upload, 4, 1, 1, 1);

        Payables_ShipperWarehouse_upload = new QPushButton(gridLayoutWidget_2);
        Payables_ShipperWarehouse_upload->setObjectName(QString::fromUtf8("Payables_ShipperWarehouse_upload"));
        Payables_ShipperWarehouse_upload->setEnabled(true);

        gridLayout_2->addWidget(Payables_ShipperWarehouse_upload, 20, 1, 1, 1);

        Payables_ShipperWarehouse = new QCheckBox(gridLayoutWidget_2);
        Payables_ShipperWarehouse->setObjectName(QString::fromUtf8("Payables_ShipperWarehouse"));
        Payables_ShipperWarehouse->setFont(font);
        Payables_ShipperWarehouse->setCursor(QCursor(Qt::PointingHandCursor));
        Payables_ShipperWarehouse->setChecked(true);

        gridLayout_2->addWidget(Payables_ShipperWarehouse, 20, 0, 1, 1);

        Payables_Harris_upload = new QPushButton(gridLayoutWidget_2);
        Payables_Harris_upload->setObjectName(QString::fromUtf8("Payables_Harris_upload"));
        Payables_Harris_upload->setEnabled(true);

        gridLayout_2->addWidget(Payables_Harris_upload, 19, 1, 1, 1);

        CertOrigin = new QCheckBox(gridLayoutWidget_2);
        CertOrigin->setObjectName(QString::fromUtf8("CertOrigin"));
        CertOrigin->setFont(font);
        CertOrigin->setCursor(QCursor(Qt::PointingHandCursor));
        CertOrigin->setChecked(true);

        gridLayout_2->addWidget(CertOrigin, 4, 0, 1, 1);

        ExpInvima_Upload = new QPushButton(gridLayoutWidget_2);
        ExpInvima_Upload->setObjectName(QString::fromUtf8("ExpInvima_Upload"));

        gridLayout_2->addWidget(ExpInvima_Upload, 1, 1, 1, 1);

        Payables_Transloader_notice = new QLabel(gridLayoutWidget_2);
        Payables_Transloader_notice->setObjectName(QString::fromUtf8("Payables_Transloader_notice"));

        gridLayout_2->addWidget(Payables_Transloader_notice, 17, 2, 1, 1);

        Payables_Harris_notice = new QLabel(gridLayoutWidget_2);
        Payables_Harris_notice->setObjectName(QString::fromUtf8("Payables_Harris_notice"));

        gridLayout_2->addWidget(Payables_Harris_notice, 19, 2, 1, 1);

        Transloader_upload = new QPushButton(gridLayoutWidget_2);
        Transloader_upload->setObjectName(QString::fromUtf8("Transloader_upload"));

        gridLayout_2->addWidget(Transloader_upload, 7, 1, 1, 1);

        CustomerPO = new QCheckBox(gridLayoutWidget_2);
        CustomerPO->setObjectName(QString::fromUtf8("CustomerPO"));
        CustomerPO->setFont(font);
        CustomerPO->setCursor(QCursor(Qt::PointingHandCursor));
        CustomerPO->setChecked(true);

        gridLayout_2->addWidget(CustomerPO, 10, 0, 1, 1);

        Payables_Transloader_upload = new QPushButton(gridLayoutWidget_2);
        Payables_Transloader_upload->setObjectName(QString::fromUtf8("Payables_Transloader_upload"));
        Payables_Transloader_upload->setEnabled(true);

        gridLayout_2->addWidget(Payables_Transloader_upload, 17, 1, 1, 1);

        HarrisEmails_upload = new QPushButton(gridLayoutWidget_2);
        HarrisEmails_upload->setObjectName(QString::fromUtf8("HarrisEmails_upload"));

        gridLayout_2->addWidget(HarrisEmails_upload, 9, 1, 1, 1);

        payables_TruckFreight_notice = new QLabel(gridLayoutWidget_2);
        payables_TruckFreight_notice->setObjectName(QString::fromUtf8("payables_TruckFreight_notice"));

        gridLayout_2->addWidget(payables_TruckFreight_notice, 18, 2, 1, 1);

        ExpInvima_notice = new QLabel(gridLayoutWidget_2);
        ExpInvima_notice->setObjectName(QString::fromUtf8("ExpInvima_notice"));

        gridLayout_2->addWidget(ExpInvima_notice, 1, 2, 1, 1);

        CustomerPO_notice = new QLabel(gridLayoutWidget_2);
        CustomerPO_notice->setObjectName(QString::fromUtf8("CustomerPO_notice"));

        gridLayout_2->addWidget(CustomerPO_notice, 10, 2, 1, 1);

        CaftaNafta_notice = new QLabel(gridLayoutWidget_2);
        CaftaNafta_notice->setObjectName(QString::fromUtf8("CaftaNafta_notice"));

        gridLayout_2->addWidget(CaftaNafta_notice, 5, 2, 1, 1);

        payables_TruckFreight_upload = new QPushButton(gridLayoutWidget_2);
        payables_TruckFreight_upload->setObjectName(QString::fromUtf8("payables_TruckFreight_upload"));
        payables_TruckFreight_upload->setEnabled(true);

        gridLayout_2->addWidget(payables_TruckFreight_upload, 18, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        FreightContract = new QCheckBox(gridLayoutWidget_2);
        FreightContract->setObjectName(QString::fromUtf8("FreightContract"));
        FreightContract->setFont(font);
        FreightContract->setCursor(QCursor(Qt::PointingHandCursor));
        FreightContract->setChecked(true);

        gridLayout_2->addWidget(FreightContract, 6, 0, 1, 1);

        HarrisEmails_notice = new QLabel(gridLayoutWidget_2);
        HarrisEmails_notice->setObjectName(QString::fromUtf8("HarrisEmails_notice"));

        gridLayout_2->addWidget(HarrisEmails_notice, 9, 2, 1, 1);

        OtherEmails = new QCheckBox(gridLayoutWidget_2);
        OtherEmails->setObjectName(QString::fromUtf8("OtherEmails"));
        OtherEmails->setFont(font);
        OtherEmails->setCursor(QCursor(Qt::PointingHandCursor));
        OtherEmails->setChecked(true);

        gridLayout_2->addWidget(OtherEmails, 11, 0, 1, 1);

        ListadeEmpaque_notice = new QLabel(gridLayoutWidget_2);
        ListadeEmpaque_notice->setObjectName(QString::fromUtf8("ListadeEmpaque_notice"));

        gridLayout_2->addWidget(ListadeEmpaque_notice, 3, 2, 1, 1);

        FacturaComercial_notice = new QLabel(gridLayoutWidget_2);
        FacturaComercial_notice->setObjectName(QString::fromUtf8("FacturaComercial_notice"));

        gridLayout_2->addWidget(FacturaComercial_notice, 2, 2, 1, 1);

        FacturaComercial_upload = new QPushButton(gridLayoutWidget_2);
        FacturaComercial_upload->setObjectName(QString::fromUtf8("FacturaComercial_upload"));

        gridLayout_2->addWidget(FacturaComercial_upload, 2, 1, 1, 1);

        Payables_ShipperWarehouse_notice = new QLabel(gridLayoutWidget_2);
        Payables_ShipperWarehouse_notice->setObjectName(QString::fromUtf8("Payables_ShipperWarehouse_notice"));

        gridLayout_2->addWidget(Payables_ShipperWarehouse_notice, 20, 2, 1, 1);

        Harris = new QCheckBox(gridLayoutWidget_2);
        Harris->setObjectName(QString::fromUtf8("Harris"));
        Harris->setFont(font);
        Harris->setCursor(QCursor(Qt::PointingHandCursor));
        Harris->setChecked(true);

        gridLayout_2->addWidget(Harris, 8, 0, 1, 1);

        Payables_Transloader = new QCheckBox(gridLayoutWidget_2);
        Payables_Transloader->setObjectName(QString::fromUtf8("Payables_Transloader"));
        Payables_Transloader->setFont(font);
        Payables_Transloader->setCursor(QCursor(Qt::PointingHandCursor));
        Payables_Transloader->setChecked(true);

        gridLayout_2->addWidget(Payables_Transloader, 17, 0, 1, 1);

        Transloader = new QCheckBox(gridLayoutWidget_2);
        Transloader->setObjectName(QString::fromUtf8("Transloader"));
        Transloader->setFont(font);
        Transloader->setCursor(QCursor(Qt::PointingHandCursor));
        Transloader->setChecked(true);

        gridLayout_2->addWidget(Transloader, 7, 0, 1, 1);

        CaftaNafta = new QCheckBox(gridLayoutWidget_2);
        CaftaNafta->setObjectName(QString::fromUtf8("CaftaNafta"));
        CaftaNafta->setFont(font);
        CaftaNafta->setCursor(QCursor(Qt::PointingHandCursor));
        CaftaNafta->setChecked(true);

        gridLayout_2->addWidget(CaftaNafta, 5, 0, 1, 1);

        CustomerPO_upload = new QPushButton(gridLayoutWidget_2);
        CustomerPO_upload->setObjectName(QString::fromUtf8("CustomerPO_upload"));

        gridLayout_2->addWidget(CustomerPO_upload, 10, 1, 1, 1);

        ListadeEmpaque = new QCheckBox(gridLayoutWidget_2);
        ListadeEmpaque->setObjectName(QString::fromUtf8("ListadeEmpaque"));
        ListadeEmpaque->setFont(font);
        ListadeEmpaque->setCursor(QCursor(Qt::PointingHandCursor));
        ListadeEmpaque->setChecked(true);

        gridLayout_2->addWidget(ListadeEmpaque, 3, 0, 1, 1);

        CaftaNafta_upload = new QPushButton(gridLayoutWidget_2);
        CaftaNafta_upload->setObjectName(QString::fromUtf8("CaftaNafta_upload"));

        gridLayout_2->addWidget(CaftaNafta_upload, 5, 1, 1, 1);

        OtherEmails_notice = new QLabel(gridLayoutWidget_2);
        OtherEmails_notice->setObjectName(QString::fromUtf8("OtherEmails_notice"));

        gridLayout_2->addWidget(OtherEmails_notice, 11, 2, 1, 1);

        Harris_upload = new QPushButton(gridLayoutWidget_2);
        Harris_upload->setObjectName(QString::fromUtf8("Harris_upload"));

        gridLayout_2->addWidget(Harris_upload, 8, 1, 1, 1);

        Harris_notice = new QLabel(gridLayoutWidget_2);
        Harris_notice->setObjectName(QString::fromUtf8("Harris_notice"));

        gridLayout_2->addWidget(Harris_notice, 8, 2, 1, 1);

        FreightContract_notice = new QLabel(gridLayoutWidget_2);
        FreightContract_notice->setObjectName(QString::fromUtf8("FreightContract_notice"));

        gridLayout_2->addWidget(FreightContract_notice, 6, 2, 1, 1);

        ListadeEmpaque_upload = new QPushButton(gridLayoutWidget_2);
        ListadeEmpaque_upload->setObjectName(QString::fromUtf8("ListadeEmpaque_upload"));

        gridLayout_2->addWidget(ListadeEmpaque_upload, 3, 1, 1, 1);

        reloadButton = new QCommandLinkButton(createFile);
        reloadButton->setObjectName(QString::fromUtf8("reloadButton"));
        reloadButton->setGeometry(QRect(240, 30, 31, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pictures/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        reloadButton->setIcon(icon);
        progressBar_save_createFile = new QProgressBar(createFile);
        progressBar_save_createFile->setObjectName(QString::fromUtf8("progressBar_save_createFile"));
        progressBar_save_createFile->setGeometry(QRect(1000, 530, 151, 16));
        progressBar_save_createFile->setValue(0);
        progressBar_save_createFile->setTextVisible(false);
        tabWidget->addTab(createFile, QString());
        runArchiveCheck = new QWidget();
        runArchiveCheck->setObjectName(QString::fromUtf8("runArchiveCheck"));
        WAEX_logo_2 = new QLabel(runArchiveCheck);
        WAEX_logo_2->setObjectName(QString::fromUtf8("WAEX_logo_2"));
        WAEX_logo_2->setGeometry(QRect(855, 5, 321, 111));
        WAEX_logo_2->setScaledContents(true);
        workingDirectory = new QLabel(runArchiveCheck);
        workingDirectory->setObjectName(QString::fromUtf8("workingDirectory"));
        workingDirectory->setGeometry(QRect(110, 30, 399, 16));
        label_3 = new QLabel(runArchiveCheck);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 30, 111, 16));
        label_3->setFont(font);
        archiveCheckButton = new QPushButton(runArchiveCheck);
        archiveCheckButton->setObjectName(QString::fromUtf8("archiveCheckButton"));
        archiveCheckButton->setGeometry(QRect(20, 60, 91, 21));
        tableView = new QTableView(runArchiveCheck);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(260, 130, 911, 401));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setVisible(false);
        label_6 = new QLabel(runArchiveCheck);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(66, 100, 71, 21));
        QFont font1;
        font1.setUnderline(true);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        archivePBar = new QProgressBar(runArchiveCheck);
        archivePBar->setObjectName(QString::fromUtf8("archivePBar"));
        archivePBar->setGeometry(QRect(210, 50, 118, 23));
        archivePBar->setValue(0);
        archivePBar->setInvertedAppearance(false);
        layoutWidget1 = new QWidget(runArchiveCheck);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 130, 131, 41));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        workingDirectory_2 = new QLabel(layoutWidget1);
        workingDirectory_2->setObjectName(QString::fromUtf8("workingDirectory_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, workingDirectory_2);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        workingDirectory_3 = new QLabel(layoutWidget1);
        workingDirectory_3->setObjectName(QString::fromUtf8("workingDirectory_3"));

        formLayout->setWidget(1, QFormLayout::FieldRole, workingDirectory_3);

        label_9 = new QLabel(runArchiveCheck);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(270, 110, 61, 16));
        QFont font2;
        font2.setPointSize(12);
        label_9->setFont(font2);
        label_10 = new QLabel(runArchiveCheck);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(360, 110, 131, 21));
        label_10->setFont(font2);
        tabWidget->addTab(runArchiveCheck, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1198, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Mex Produce", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Domestic", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Mex Direct", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Overseas", nullptr));

        saveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        POInput->setInputMask(QString());
        POInput->setPlaceholderText(QApplication::translate("MainWindow", "PO#", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "PO#:", nullptr));
        openFolder->setText(QApplication::translate("MainWindow", "Open Folder", nullptr));
        WAEX_logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Notes PO# :", nullptr));
        PoLabel->setText(QApplication::translate("MainWindow", "NULL", nullptr));
        mexP_Payable_Shipper_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        noticeSaleConf->setText(QApplication::translate("MainWindow", "No", nullptr));
        noticeProduceInv->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_Payables_Carriers_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        noticeSpreadsheets->setText(QApplication::translate("MainWindow", "No", nullptr));
        noticeShipperConf->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_SignedSale->setText(QApplication::translate("MainWindow", "Signed Sale Conf.", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Uploaded?", nullptr));
        mexP_Passing_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        noticePayableShipper->setText(QApplication::translate("MainWindow", "No", nullptr));
        noticePhyto->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_SignedSale_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_ShipperConf_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_SaleConf_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        noticeCarrierConf->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_SaleConf->setText(QApplication::translate("MainWindow", "Sale Conf", nullptr));
        mexP_Passing->setText(QApplication::translate("MainWindow", "Passing", nullptr));
        mexP_Payables_Carriers->setText(QApplication::translate("MainWindow", "Payables-Carriers", nullptr));
        mexP_ProduceInv->setText(QApplication::translate("MainWindow", "Produce Inv. ", nullptr));
        mexP_Spreadsheets_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        noticeSignedSaleConf->setText(QApplication::translate("MainWindow", "No", nullptr));
        noticePedimento->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_Phyto->setText(QApplication::translate("MainWindow", "Phyto", nullptr));
        mexP_ShipperConf->setText(QApplication::translate("MainWindow", "Shipper Conf", nullptr));
        mexP_ProduceInv_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Pedimento->setText(QApplication::translate("MainWindow", "Pedimento", nullptr));
        mexP_Invoice->setText(QApplication::translate("MainWindow", "Invoice", nullptr));
        mexP_Payable_Shipper->setText(QApplication::translate("MainWindow", "Payables-Shipper", nullptr));
        mexP_Invoice_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_CarrierConf_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        noticeInvoice->setText(QApplication::translate("MainWindow", "No", nullptr));
        noticePayableCarriers->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_Pedimento_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_CarrierConf->setText(QApplication::translate("MainWindow", "Carrier Conf", nullptr));
        mexP_Spreadsheets->setText(QApplication::translate("MainWindow", "Spreadsheets", nullptr));
        noticePassing->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_Phyto_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        receipts->setText(QApplication::translate("MainWindow", "Receipts", nullptr));
        receipts_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        receipts_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        HarrisEmails->setText(QApplication::translate("MainWindow", "Harris Emails", nullptr));
        CertOrigin_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        FreightContract_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        payables_TruckFreight->setText(QApplication::translate("MainWindow", "Payables-Truck/Freight", nullptr));
        OtherEmails_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        ExpInvima->setText(QApplication::translate("MainWindow", "Exportacion/ INVIMA", nullptr));
        FacturaComercial->setText(QApplication::translate("MainWindow", "Factura Comercial", nullptr));
        Payables_Harris->setText(QApplication::translate("MainWindow", "Payables-Harris", nullptr));
        Transloader_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        CertOrigin_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        Payables_ShipperWarehouse_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        Payables_ShipperWarehouse->setText(QApplication::translate("MainWindow", "Payables-Shipper/Warehouse", nullptr));
        Payables_Harris_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        CertOrigin->setText(QApplication::translate("MainWindow", "Certificate of Origin", nullptr));
        ExpInvima_Upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        Payables_Transloader_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        Payables_Harris_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        Transloader_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        CustomerPO->setText(QApplication::translate("MainWindow", "Customer PO", nullptr));
        Payables_Transloader_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        HarrisEmails_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        payables_TruckFreight_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        ExpInvima_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        CustomerPO_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        CaftaNafta_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        payables_TruckFreight_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Uploaded?", nullptr));
        FreightContract->setText(QApplication::translate("MainWindow", "Freight Serv Contract", nullptr));
        HarrisEmails_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        OtherEmails->setText(QApplication::translate("MainWindow", "Other Emails", nullptr));
        ListadeEmpaque_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        FacturaComercial_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        FacturaComercial_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        Payables_ShipperWarehouse_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        Harris->setText(QApplication::translate("MainWindow", "Harris", nullptr));
        Payables_Transloader->setText(QApplication::translate("MainWindow", "Payables-Transloader", nullptr));
        Transloader->setText(QApplication::translate("MainWindow", "Transloader", nullptr));
        CaftaNafta->setText(QApplication::translate("MainWindow", "CAFTA/NAFTA", nullptr));
        CustomerPO_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        ListadeEmpaque->setText(QApplication::translate("MainWindow", "Lista de Empaque", nullptr));
        CaftaNafta_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        OtherEmails_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        Harris_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        Harris_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        FreightContract_notice->setText(QApplication::translate("MainWindow", "No", nullptr));
        ListadeEmpaque_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        reloadButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(createFile), QApplication::translate("MainWindow", "Create File", nullptr));
        WAEX_logo_2->setText(QString());
        workingDirectory->setText(QApplication::translate("MainWindow", "NULL", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Working Directory:", nullptr));
        archiveCheckButton->setText(QApplication::translate("MainWindow", "Run Check", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Summary", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Total Errors:", nullptr));
        workingDirectory_2->setText(QApplication::translate("MainWindow", "NULL", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Files Affected", nullptr));
        workingDirectory_3->setText(QApplication::translate("MainWindow", "NULL", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "PO#", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Missing Files ->", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(runArchiveCheck), QApplication::translate("MainWindow", "Run Archive Check", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
