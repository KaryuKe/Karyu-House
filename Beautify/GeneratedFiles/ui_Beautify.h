/********************************************************************************
** Form generated from reading UI file 'Beautify.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEAUTIFY_H
#define UI_BEAUTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BeautifyClass
{
public:

    void setupUi(QWidget *BeautifyClass)
    {
        if (BeautifyClass->objectName().isEmpty())
            BeautifyClass->setObjectName(QString::fromUtf8("BeautifyClass"));
        BeautifyClass->resize(600, 400);

        retranslateUi(BeautifyClass);

        QMetaObject::connectSlotsByName(BeautifyClass);
    } // setupUi

    void retranslateUi(QWidget *BeautifyClass)
    {
        BeautifyClass->setWindowTitle(QCoreApplication::translate("BeautifyClass", "Beautify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BeautifyClass: public Ui_BeautifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEAUTIFY_H
