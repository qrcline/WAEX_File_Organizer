/********************************************************************************
** Form generated from reading UI file 'helpcenterd.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPCENTERD_H
#define UI_HELPCENTERD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpCenterD
{
public:

    void setupUi(QWidget *helpCenterD)
    {
        if (helpCenterD->objectName().isEmpty())
            helpCenterD->setObjectName(QString::fromUtf8("helpCenterD"));
        helpCenterD->resize(522, 626);

        retranslateUi(helpCenterD);

        QMetaObject::connectSlotsByName(helpCenterD);
    } // setupUi

    void retranslateUi(QWidget *helpCenterD)
    {
        helpCenterD->setWindowTitle(QCoreApplication::translate("helpCenterD", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpCenterD: public Ui_helpCenterD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPCENTERD_H
