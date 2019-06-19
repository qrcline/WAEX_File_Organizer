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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QStackedWidget *stackedSelection;
    QWidget *pageMP;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *mexP_ProduceInv_upload;
    QCheckBox *mexP_SaleConf;
    QPushButton *mexP_SignedSale_upload;
    QPushButton *mexP_Invoice_upload;
    QCheckBox *mexP_Phyto;
    QPushButton *mexP_Passing_upload;
    QCheckBox *mexP_ShipperConf;
    QCheckBox *mexP_SignedSale;
    QPushButton *mexP_Payable_Shipper_upload;
    QPushButton *mexP_Payables_Carriers_upload;
    QCheckBox *mexP_Pedimento;
    QPushButton *mexP_Spreadsheets_upload;
    QPushButton *mexP_Pedimento_upload;
    QCheckBox *mexP_Payable_Shipper;
    QPushButton *mexP_Phyto_upload;
    QCheckBox *mexP_ProduceInv;
    QPushButton *mexP_ShipperConf_upload;
    QCheckBox *mexP_Spreadsheets;
    QPushButton *mexP_CarrierConf_upload;
    QCheckBox *mexP_Passing;
    QCheckBox *mexP_Invoice;
    QCheckBox *mexP_CarrierConf;
    QCheckBox *mexP_Payables_Carriers;
    QLabel *label_3;
    QPushButton *mexP_SaleConf_upload;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *page_2;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *saveButton;
    QLineEdit *POInput;
    QLabel *label_2;
    QPushButton *openFolder;
    QLabel *WAEX_logo;
    QWidget *runArchiveCheck;
    QLabel *WAEX_logo_2;
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
        stackedSelection = new QStackedWidget(createFile);
        stackedSelection->setObjectName(QString::fromUtf8("stackedSelection"));
        stackedSelection->setGeometry(QRect(30, 100, 391, 421));
        pageMP = new QWidget();
        pageMP->setObjectName(QString::fromUtf8("pageMP"));
        gridLayoutWidget = new QWidget(pageMP);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 30, 371, 381));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mexP_ProduceInv_upload = new QPushButton(gridLayoutWidget);
        mexP_ProduceInv_upload->setObjectName(QString::fromUtf8("mexP_ProduceInv_upload"));

        gridLayout->addWidget(mexP_ProduceInv_upload, 10, 1, 1, 1);

        mexP_SaleConf = new QCheckBox(gridLayoutWidget);
        mexP_SaleConf->setObjectName(QString::fromUtf8("mexP_SaleConf"));
        mexP_SaleConf->setFont(font);
        mexP_SaleConf->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_SaleConf->setChecked(true);

        gridLayout->addWidget(mexP_SaleConf, 7, 0, 1, 1);

        mexP_SignedSale_upload = new QPushButton(gridLayoutWidget);
        mexP_SignedSale_upload->setObjectName(QString::fromUtf8("mexP_SignedSale_upload"));

        gridLayout->addWidget(mexP_SignedSale_upload, 8, 1, 1, 1);

        mexP_Invoice_upload = new QPushButton(gridLayoutWidget);
        mexP_Invoice_upload->setObjectName(QString::fromUtf8("mexP_Invoice_upload"));

        gridLayout->addWidget(mexP_Invoice_upload, 2, 1, 1, 1);

        mexP_Phyto = new QCheckBox(gridLayoutWidget);
        mexP_Phyto->setObjectName(QString::fromUtf8("mexP_Phyto"));
        mexP_Phyto->setFont(font);
        mexP_Phyto->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Phyto->setChecked(true);

        gridLayout->addWidget(mexP_Phyto, 3, 0, 1, 1);

        mexP_Passing_upload = new QPushButton(gridLayoutWidget);
        mexP_Passing_upload->setObjectName(QString::fromUtf8("mexP_Passing_upload"));

        gridLayout->addWidget(mexP_Passing_upload, 6, 1, 1, 1);

        mexP_ShipperConf = new QCheckBox(gridLayoutWidget);
        mexP_ShipperConf->setObjectName(QString::fromUtf8("mexP_ShipperConf"));
        mexP_ShipperConf->setFont(font);
        mexP_ShipperConf->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_ShipperConf->setChecked(true);

        gridLayout->addWidget(mexP_ShipperConf, 4, 0, 1, 1);

        mexP_SignedSale = new QCheckBox(gridLayoutWidget);
        mexP_SignedSale->setObjectName(QString::fromUtf8("mexP_SignedSale"));
        mexP_SignedSale->setFont(font);
        mexP_SignedSale->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_SignedSale->setChecked(true);

        gridLayout->addWidget(mexP_SignedSale, 8, 0, 1, 1);

        mexP_Payable_Shipper_upload = new QPushButton(gridLayoutWidget);
        mexP_Payable_Shipper_upload->setObjectName(QString::fromUtf8("mexP_Payable_Shipper_upload"));

        gridLayout->addWidget(mexP_Payable_Shipper_upload, 11, 1, 1, 1);

        mexP_Payables_Carriers_upload = new QPushButton(gridLayoutWidget);
        mexP_Payables_Carriers_upload->setObjectName(QString::fromUtf8("mexP_Payables_Carriers_upload"));

        gridLayout->addWidget(mexP_Payables_Carriers_upload, 17, 1, 1, 1);

        mexP_Pedimento = new QCheckBox(gridLayoutWidget);
        mexP_Pedimento->setObjectName(QString::fromUtf8("mexP_Pedimento"));
        mexP_Pedimento->setFont(font);
        mexP_Pedimento->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Pedimento->setChecked(true);

        gridLayout->addWidget(mexP_Pedimento, 9, 0, 1, 1);

        mexP_Spreadsheets_upload = new QPushButton(gridLayoutWidget);
        mexP_Spreadsheets_upload->setObjectName(QString::fromUtf8("mexP_Spreadsheets_upload"));

        gridLayout->addWidget(mexP_Spreadsheets_upload, 1, 1, 1, 1);

        mexP_Pedimento_upload = new QPushButton(gridLayoutWidget);
        mexP_Pedimento_upload->setObjectName(QString::fromUtf8("mexP_Pedimento_upload"));

        gridLayout->addWidget(mexP_Pedimento_upload, 9, 1, 1, 1);

        mexP_Payable_Shipper = new QCheckBox(gridLayoutWidget);
        mexP_Payable_Shipper->setObjectName(QString::fromUtf8("mexP_Payable_Shipper"));
        mexP_Payable_Shipper->setFont(font);
        mexP_Payable_Shipper->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Payable_Shipper->setChecked(true);

        gridLayout->addWidget(mexP_Payable_Shipper, 11, 0, 1, 1);

        mexP_Phyto_upload = new QPushButton(gridLayoutWidget);
        mexP_Phyto_upload->setObjectName(QString::fromUtf8("mexP_Phyto_upload"));

        gridLayout->addWidget(mexP_Phyto_upload, 3, 1, 1, 1);

        mexP_ProduceInv = new QCheckBox(gridLayoutWidget);
        mexP_ProduceInv->setObjectName(QString::fromUtf8("mexP_ProduceInv"));
        mexP_ProduceInv->setFont(font);
        mexP_ProduceInv->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_ProduceInv->setChecked(true);

        gridLayout->addWidget(mexP_ProduceInv, 10, 0, 1, 1);

        mexP_ShipperConf_upload = new QPushButton(gridLayoutWidget);
        mexP_ShipperConf_upload->setObjectName(QString::fromUtf8("mexP_ShipperConf_upload"));

        gridLayout->addWidget(mexP_ShipperConf_upload, 4, 1, 1, 1);

        mexP_Spreadsheets = new QCheckBox(gridLayoutWidget);
        mexP_Spreadsheets->setObjectName(QString::fromUtf8("mexP_Spreadsheets"));
        mexP_Spreadsheets->setFont(font);
        mexP_Spreadsheets->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Spreadsheets->setChecked(true);

        gridLayout->addWidget(mexP_Spreadsheets, 1, 0, 1, 1);

        mexP_CarrierConf_upload = new QPushButton(gridLayoutWidget);
        mexP_CarrierConf_upload->setObjectName(QString::fromUtf8("mexP_CarrierConf_upload"));

        gridLayout->addWidget(mexP_CarrierConf_upload, 5, 1, 1, 1);

        mexP_Passing = new QCheckBox(gridLayoutWidget);
        mexP_Passing->setObjectName(QString::fromUtf8("mexP_Passing"));
        mexP_Passing->setFont(font);
        mexP_Passing->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Passing->setChecked(true);

        gridLayout->addWidget(mexP_Passing, 6, 0, 1, 1);

        mexP_Invoice = new QCheckBox(gridLayoutWidget);
        mexP_Invoice->setObjectName(QString::fromUtf8("mexP_Invoice"));
        mexP_Invoice->setFont(font);
        mexP_Invoice->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Invoice->setChecked(true);

        gridLayout->addWidget(mexP_Invoice, 2, 0, 1, 1);

        mexP_CarrierConf = new QCheckBox(gridLayoutWidget);
        mexP_CarrierConf->setObjectName(QString::fromUtf8("mexP_CarrierConf"));
        mexP_CarrierConf->setFont(font);
        mexP_CarrierConf->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_CarrierConf->setChecked(true);

        gridLayout->addWidget(mexP_CarrierConf, 5, 0, 1, 1);

        mexP_Payables_Carriers = new QCheckBox(gridLayoutWidget);
        mexP_Payables_Carriers->setObjectName(QString::fromUtf8("mexP_Payables_Carriers"));
        mexP_Payables_Carriers->setFont(font);
        mexP_Payables_Carriers->setCursor(QCursor(Qt::PointingHandCursor));
        mexP_Payables_Carriers->setChecked(true);

        gridLayout->addWidget(mexP_Payables_Carriers, 17, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        mexP_SaleConf_upload = new QPushButton(gridLayoutWidget);
        mexP_SaleConf_upload->setObjectName(QString::fromUtf8("mexP_SaleConf_upload"));

        gridLayout->addWidget(mexP_SaleConf_upload, 7, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 9, 2, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 10, 2, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 11, 2, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 17, 2, 1, 1);

        stackedSelection->addWidget(pageMP);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedSelection->addWidget(page_2);
        textEdit = new QTextEdit(createFile);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(690, 240, 461, 241));
        label = new QLabel(createFile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 220, 47, 13));
        label->setFont(font);
        saveButton = new QPushButton(createFile);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(1069, 510, 101, 31));
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
        tabWidget->addTab(createFile, QString());
        runArchiveCheck = new QWidget();
        runArchiveCheck->setObjectName(QString::fromUtf8("runArchiveCheck"));
        WAEX_logo_2 = new QLabel(runArchiveCheck);
        WAEX_logo_2->setObjectName(QString::fromUtf8("WAEX_logo_2"));
        WAEX_logo_2->setGeometry(QRect(855, 5, 321, 111));
        WAEX_logo_2->setScaledContents(true);
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
        menuFile->addAction(actionSettings);
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedSelection->setCurrentIndex(0);


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

        mexP_ProduceInv_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_SaleConf->setText(QApplication::translate("MainWindow", "Sale Conf", nullptr));
        mexP_SignedSale_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Invoice_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Phyto->setText(QApplication::translate("MainWindow", "Phyto", nullptr));
        mexP_Passing_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_ShipperConf->setText(QApplication::translate("MainWindow", "Shipper Conf", nullptr));
        mexP_SignedSale->setText(QApplication::translate("MainWindow", "Signed Sale Conf.", nullptr));
        mexP_Payable_Shipper_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Payables_Carriers_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Pedimento->setText(QApplication::translate("MainWindow", "Pedimento", nullptr));
        mexP_Spreadsheets_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Pedimento_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Payable_Shipper->setText(QApplication::translate("MainWindow", "Payables-Shipper", nullptr));
        mexP_Phyto_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_ProduceInv->setText(QApplication::translate("MainWindow", "Produce Inv. ", nullptr));
        mexP_ShipperConf_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Spreadsheets->setText(QApplication::translate("MainWindow", "Spreadsheets", nullptr));
        mexP_CarrierConf_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        mexP_Passing->setText(QApplication::translate("MainWindow", "Passing", nullptr));
        mexP_Invoice->setText(QApplication::translate("MainWindow", "Invoice", nullptr));
        mexP_CarrierConf->setText(QApplication::translate("MainWindow", "Carrier Conf", nullptr));
        mexP_Payables_Carriers->setText(QApplication::translate("MainWindow", "Payables-Carriers", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "No", nullptr));
        mexP_SaleConf_upload->setText(QApplication::translate("MainWindow", "Choose File", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Uploaded?", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "No", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "No", nullptr));
        label->setText(QApplication::translate("MainWindow", "Notes:", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        POInput->setInputMask(QString());
        label_2->setText(QApplication::translate("MainWindow", "PO#:", nullptr));
        openFolder->setText(QApplication::translate("MainWindow", "Open Folder", nullptr));
        WAEX_logo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(createFile), QApplication::translate("MainWindow", "Create File", nullptr));
        WAEX_logo_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(runArchiveCheck), QApplication::translate("MainWindow", "Run Archive Check", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
