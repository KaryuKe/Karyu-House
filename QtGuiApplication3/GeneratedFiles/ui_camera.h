/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameraClass
{
public:

    void setupUi(QWidget *cameraClass)
    {
        if (cameraClass->objectName().isEmpty())
            cameraClass->setObjectName(QString::fromUtf8("cameraClass"));
        cameraClass->resize(600, 400);

        retranslateUi(cameraClass);

        QMetaObject::connectSlotsByName(cameraClass);
    } // setupUi

    void retranslateUi(QWidget *cameraClass)
    {
        cameraClass->setWindowTitle(QCoreApplication::translate("cameraClass", "camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cameraClass: public Ui_cameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
