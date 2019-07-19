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
    QComboBox *settingsColorScheme;
    QLabel *label_2;
    QCheckBox *settingsOpenFolder;
    QCheckBox *settingsToolTips;
    QPushButton *settingsClose;
    QLabel *label_3;

    void setupUi(QDialog *settingD)
    {
        if (settingD->objectName().isEmpty())
            settingD->setObjectName(QString::fromUtf8("settingD"));
        settingD->resize(300, 200);
        settingD->setMinimumSize(QSize(300, 200));
        settingD->setMaximumSize(QSize(300, 200));
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
        settingsColorScheme = new QComboBox(layoutWidget);
        settingsColorScheme->addItem(QString());
        settingsColorScheme->addItem(QString());
        settingsColorScheme->setObjectName(QString::fromUtf8("settingsColorScheme"));
        settingsColorScheme->setEnabled(true);

        horizontalLayout->addWidget(settingsColorScheme);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        settingsOpenFolder = new QCheckBox(layoutWidget);
        settingsOpenFolder->setObjectName(QString::fromUtf8("settingsOpenFolder"));

        verticalLayout->addWidget(settingsOpenFolder);

        settingsToolTips = new QCheckBox(layoutWidget);
        settingsToolTips->setObjectName(QString::fromUtf8("settingsToolTips"));

        verticalLayout->addWidget(settingsToolTips);

        settingsClose = new QPushButton(settingD);
        settingsClose->setObjectName(QString::fromUtf8("settingsClose"));
        settingsClose->setGeometry(QRect(190, 160, 85, 25));
        settingsClose->setCursor(QCursor(Qt::ArrowCursor));
        settingsClose->setStyleSheet(QString::fromUtf8("border: 1px solid red;\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(49, 245, 255);\n"
"border-radius: 5px; "));
        label_3 = new QLabel(settingD);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 221, 16));

        retranslateUi(settingD);

        QMetaObject::connectSlotsByName(settingD);
    } // setupUi

    void retranslateUi(QDialog *settingD)
    {
        settingD->setWindowTitle(QCoreApplication::translate("settingD", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("settingD", "Settings", nullptr));
        settingsColorScheme->setItemText(0, QCoreApplication::translate("settingD", "Light", nullptr));
        settingsColorScheme->setItemText(1, QCoreApplication::translate("settingD", "Dark", nullptr));

        label_2->setText(QCoreApplication::translate("settingD", "Color Scheme", nullptr));
        settingsOpenFolder->setText(QCoreApplication::translate("settingD", "Open folder on Enter press", nullptr));
        settingsToolTips->setText(QCoreApplication::translate("settingD", "Enable Tool Tips", nullptr));
        settingsClose->setText(QCoreApplication::translate("settingD", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("settingD", "Note: Restart Application to apply settings. ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingD: public Ui_settingD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGD_H
