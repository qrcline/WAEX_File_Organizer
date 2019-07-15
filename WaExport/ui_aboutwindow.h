/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *aboutLogo;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QString::fromUtf8("AboutWindow"));
        AboutWindow->resize(497, 269);
        AboutWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        aboutLogo = new QLabel(AboutWindow);
        aboutLogo->setObjectName(QString::fromUtf8("aboutLogo"));
        aboutLogo->setGeometry(QRect(20, 30, 161, 201));
        pushButton = new QPushButton(AboutWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(399, 230, 85, 25));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border: 1px solid red;\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(49, 245, 255);\n"
"border-radius: 5px; "));
        widget = new QWidget(AboutWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 30, 199, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_5);


        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QCoreApplication::translate("AboutWindow", "Dialog", nullptr));
        aboutLogo->setText(QString());
        pushButton->setText(QCoreApplication::translate("AboutWindow", "Close", nullptr));
        label->setText(QCoreApplication::translate("AboutWindow", "WAEX Filing System  0.3", nullptr));
        label_2->setText(QCoreApplication::translate("AboutWindow", "Based on Qt 5.13.0 (MSVC 2017, 64bit)", nullptr));
        label_3->setText(QCoreApplication::translate("AboutWindow", "Built on Date", nullptr));
        label_4->setText(QCoreApplication::translate("AboutWindow", "Created by: Quinton Cline", nullptr));
        label_5->setText(QCoreApplication::translate("AboutWindow", "\302\251 Washington Export LLC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
