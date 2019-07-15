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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLabel *label_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;

    void setupUi(QDialog *settingD)
    {
        if (settingD->objectName().isEmpty())
            settingD->setObjectName(QString::fromUtf8("settingD"));
        settingD->resize(275, 189);
        label = new QLabel(settingD);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 10, 47, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        layoutWidget = new QWidget(settingD);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 171, 76));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        pushButton = new QPushButton(settingD);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 130, 85, 25));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border: 1px solid red;\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(49, 245, 255);\n"
"border-radius: 5px; "));

        retranslateUi(settingD);

        QMetaObject::connectSlotsByName(settingD);
    } // setupUi

    void retranslateUi(QDialog *settingD)
    {
        settingD->setWindowTitle(QCoreApplication::translate("settingD", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("settingD", "Settings", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("settingD", "Light", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("settingD", "Dark", nullptr));

        label_2->setText(QCoreApplication::translate("settingD", "Color Scheme", nullptr));
        checkBox->setText(QCoreApplication::translate("settingD", "Open folder on Enter press", nullptr));
        checkBox_2->setText(QCoreApplication::translate("settingD", "Enable Tool Tips", nullptr));
        pushButton->setText(QCoreApplication::translate("settingD", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingD: public Ui_settingD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGD_H
