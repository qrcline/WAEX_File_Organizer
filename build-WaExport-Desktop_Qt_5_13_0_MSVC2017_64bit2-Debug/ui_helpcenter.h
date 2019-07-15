/********************************************************************************
** Form generated from reading UI file 'helpcenter.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPCENTER_H
#define UI_HELPCENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpCenter
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HelpCenter)
    {
        if (HelpCenter->objectName().isEmpty())
            HelpCenter->setObjectName(QString::fromUtf8("HelpCenter"));
        HelpCenter->resize(800, 600);
        centralwidget = new QWidget(HelpCenter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 260, 47, 13));
        HelpCenter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HelpCenter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        HelpCenter->setMenuBar(menubar);
        statusbar = new QStatusBar(HelpCenter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HelpCenter->setStatusBar(statusbar);

        retranslateUi(HelpCenter);

        QMetaObject::connectSlotsByName(HelpCenter);
    } // setupUi

    void retranslateUi(QMainWindow *HelpCenter)
    {
        HelpCenter->setWindowTitle(QCoreApplication::translate("HelpCenter", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("HelpCenter", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpCenter: public Ui_HelpCenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPCENTER_H
