/********************************************************************************
** Form generated from reading UI file 'settingd.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGD_H
#define UI_SETTINGD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingD
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *settingsOpenFolder;
    QCheckBox *settingsToolTips;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *settingsClose;
    QLabel *label_3;
    QFrame *frame;
    QLabel *label_5;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *settingD)
    {
        if (settingD->objectName().isEmpty())
            settingD->setObjectName(QString::fromUtf8("settingD"));
        settingD->resize(300, 400);
        settingD->setMinimumSize(QSize(300, 200));
        settingD->setMaximumSize(QSize(300, 400));
        label = new QLabel(settingD);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 301, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(settingD);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 251, 124));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        settingsOpenFolder = new QCheckBox(layoutWidget);
        settingsOpenFolder->setObjectName(QString::fromUtf8("settingsOpenFolder"));

        verticalLayout->addWidget(settingsOpenFolder);

        settingsToolTips = new QCheckBox(layoutWidget);
        settingsToolTips->setObjectName(QString::fromUtf8("settingsToolTips"));

        verticalLayout->addWidget(settingsToolTips);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font1;
        font1.setPointSize(10);
        lineEdit->setFont(font1);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        settingsClose = new QPushButton(settingD);
        settingsClose->setObjectName(QString::fromUtf8("settingsClose"));
        settingsClose->setGeometry(QRect(210, 370, 85, 25));
        settingsClose->setCursor(QCursor(Qt::ArrowCursor));
        settingsClose->setStyleSheet(QString::fromUtf8("border: 1px solid red;\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(49, 245, 255);\n"
"border-radius: 5px; "));
        label_3 = new QLabel(settingD);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 370, 221, 16));
        frame = new QFrame(settingD);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 180, 261, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 0, 251, 20));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 241, 56));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_3);


        retranslateUi(settingD);

        QMetaObject::connectSlotsByName(settingD);
    } // setupUi

    void retranslateUi(QDialog *settingD)
    {
        settingD->setWindowTitle(QCoreApplication::translate("settingD", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("settingD", "Settings", nullptr));
        settingsOpenFolder->setText(QCoreApplication::translate("settingD", "Open folder on Enter press", nullptr));
        settingsToolTips->setText(QCoreApplication::translate("settingD", "Enable Tool Tips", nullptr));
        label_4->setText(QCoreApplication::translate("settingD", "User Name:", nullptr));
        settingsClose->setText(QCoreApplication::translate("settingD", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("settingD", " Restart Application to apply settings. ", nullptr));
        label_5->setText(QCoreApplication::translate("settingD", "Glo Board Settings", nullptr));
        label_6->setText(QCoreApplication::translate("settingD", "client_id:", nullptr));
        label_7->setText(QCoreApplication::translate("settingD", "client_secret:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingD: public Ui_settingD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGD_H
