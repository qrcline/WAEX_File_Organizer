/********************************************************************************
** Form generated from reading UI file 'helpcenter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPCENTER_H
#define UI_HELPCENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpCenter
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HelpCenter)
    {
        if (HelpCenter->objectName().isEmpty())
            HelpCenter->setObjectName(QString::fromUtf8("HelpCenter"));
        HelpCenter->resize(1000, 700);
        HelpCenter->setMinimumSize(QSize(1000, 700));
        HelpCenter->setMaximumSize(QSize(1000, 700));
        HelpCenter->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"color: #333;\n"
"border: 1px solid #052488;\n"
"/*font: 8pt \"Myriad Pro\";*/\n"
"border-radius: 7px;\n"
"/*padding: 3px;*/\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.34, stop: 0 #fff, stop: 1 #888);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.34, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"fx: 0.4, fy: -0.1,\n"
"radius: 1.34, stop: 0 #fff, stop: 1 #ddd);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"background-color:#727375;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlinearg"
                        "radient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:FF0000;;\n"
""
                        "background-color:transparent;\n"
"border: 1px solid #0505f7;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        centralwidget = new QWidget(HelpCenter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1041, 641));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 256, 271));
        QFont font;
        font.setPointSize(12);
        textBrowser->setFont(font);
        textBrowser->setAcceptDrops(false);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(280, 10, 256, 301));
        textBrowser_2->setFont(font);
        textBrowser_2->setAcceptDrops(false);
        textBrowser_2->setFrameShape(QFrame::NoFrame);
        textBrowser_2->setFrameShadow(QFrame::Plain);
        textBrowser_3 = new QTextBrowser(tab);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(560, 10, 256, 301));
        textBrowser_3->setFont(font);
        textBrowser_3->setAcceptDrops(false);
        textBrowser_3->setFrameShape(QFrame::NoFrame);
        textBrowser_3->setFrameShadow(QFrame::Plain);
        textBrowser_4 = new QTextBrowser(tab);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(10, 290, 256, 301));
        textBrowser_4->setFont(font);
        textBrowser_4->setAcceptDrops(false);
        textBrowser_4->setFrameShape(QFrame::NoFrame);
        textBrowser_4->setFrameShadow(QFrame::Plain);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        HelpCenter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HelpCenter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 20));
        HelpCenter->setMenuBar(menubar);
        statusbar = new QStatusBar(HelpCenter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HelpCenter->setStatusBar(statusbar);

        retranslateUi(HelpCenter);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HelpCenter);
    } // setupUi

    void retranslateUi(QMainWindow *HelpCenter)
    {
        HelpCenter->setWindowTitle(QApplication::translate("HelpCenter", "MainWindow", nullptr));
        textBrowser->setHtml(QApplication::translate("HelpCenter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Initial Setup</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">This program is designed to work in conjunction with a shared network drive. All the files will be stored on the network drive. This applications purpose is to facilitate the storage, formatting and retrieval of files sorted by PO#. For initial setup a folder for the year must be created on the shared network drive, the prog"
                        "ram will store and retrieve files from this location. The folders for the PO numbers will be generated by the application. </span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QApplication::translate("HelpCenter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-weight:600;\">Entering a PO#</span><span style=\" font-weight:600;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt;\">The user must first select the working directory in File-&gt;Open. This is where all the files will be saved. If selecting the working directory after PO files have been selected make sure to select t"
                        "he correct working directory and </span><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt; font-weight:600;\">NOT </span><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt;\">one of the PO files, this will cause errors. This will most likely be a file already setup and will have the year. </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt;\">The user will input the PO# generated by Famous into the PO# input box and press </span><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt; font-weight:600;\">enter</span><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt;\">. If the PO# is not already in the system, the program will prompt the user to create the file. If the PO# is in the system, the file will be loaded to view. </span></p></body></html>", nullptr));
        textBrowser_3->setHtml(QApplication::translate("HelpCenter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-weight:600;\">Required Files</span><span style=\" font-weight:600;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt;\">The required files are the ones that are needed for a specific order or PO#. This is dependent on the destination of the load or the customer. There are four different preset templates to expedite th"
                        "is process. The checked files are the ones that are required. The user can check or uncheck any of the files to meet there needs. The checking of the required files is used in the Archive check to make sure all required files are present. </span></p></body></html>", nullptr));
        textBrowser_4->setHtml(QApplication::translate("HelpCenter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-weight:600;\">Uploading Files</span><span style=\" font-weight:600;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:10pt;\">Once the user has checked a file to be a required the upload button will allow the user to upload a document to the system for that specific file. The user does not need to name the document a speci"
                        "fic name the program will copy and rename it to the correct formatting. </span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("HelpCenter", "File", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("HelpCenter", "Archive Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpCenter: public Ui_HelpCenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPCENTER_H
