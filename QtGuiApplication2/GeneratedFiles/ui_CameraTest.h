/********************************************************************************
** Form generated from reading UI file 'CameraTest.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERATEST_H
#define UI_CAMERATEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraTestClass
{
public:
    QLabel *label_camera;
    QPushButton *pushButton_open;
    QPushButton *pushButton_photo;
    QPushButton *pushButton_close;

    void setupUi(QWidget *CameraTestClass)
    {
        if (CameraTestClass->objectName().isEmpty())
            CameraTestClass->setObjectName(QString::fromUtf8("CameraTestClass"));
        CameraTestClass->resize(967, 664);
        label_camera = new QLabel(CameraTestClass);
        label_camera->setObjectName(QString::fromUtf8("label_camera"));
        label_camera->setGeometry(QRect(120, 110, 54, 12));
        pushButton_open = new QPushButton(CameraTestClass);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(40, 450, 75, 23));
        pushButton_photo = new QPushButton(CameraTestClass);
        pushButton_photo->setObjectName(QString::fromUtf8("pushButton_photo"));
        pushButton_photo->setGeometry(QRect(150, 450, 75, 23));
        pushButton_close = new QPushButton(CameraTestClass);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(280, 450, 75, 23));

        retranslateUi(CameraTestClass);

        QMetaObject::connectSlotsByName(CameraTestClass);
    } // setupUi

    void retranslateUi(QWidget *CameraTestClass)
    {
        CameraTestClass->setWindowTitle(QCoreApplication::translate("CameraTestClass", "CameraTest", nullptr));
        label_camera->setText(QCoreApplication::translate("CameraTestClass", "TextLabel", nullptr));
        pushButton_open->setText(QCoreApplication::translate("CameraTestClass", "PushButton", nullptr));
        pushButton_photo->setText(QCoreApplication::translate("CameraTestClass", "PushButton", nullptr));
        pushButton_close->setText(QCoreApplication::translate("CameraTestClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraTestClass: public Ui_CameraTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERATEST_H
