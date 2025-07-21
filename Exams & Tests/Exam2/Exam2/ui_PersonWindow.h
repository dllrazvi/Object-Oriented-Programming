/********************************************************************************
** Form generated from reading UI file 'PersonWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONWINDOW_H
#define UI_PERSONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonWindow
{
public:
    QLabel *lblPosition;
    QCheckBox *chkNearby;
    QListWidget *listEvents;
    QLineEdit *txtName;
    QLineEdit *txtDesc;
    QLineEdit *txtLat;
    QLineEdit *txtLon;
    QLineEdit *txtDate;
    QPushButton *btnAddEvent;

    void setupUi(QWidget *PersonWindow)
    {
        if (PersonWindow->objectName().isEmpty())
            PersonWindow->setObjectName("PersonWindow");
        PersonWindow->resize(474, 444);
        lblPosition = new QLabel(PersonWindow);
        lblPosition->setObjectName("lblPosition");
        lblPosition->setGeometry(QRect(20, 10, 49, 16));
        chkNearby = new QCheckBox(PersonWindow);
        chkNearby->setObjectName("chkNearby");
        chkNearby->setGeometry(QRect(10, 40, 77, 22));
        listEvents = new QListWidget(PersonWindow);
        listEvents->setObjectName("listEvents");
        listEvents->setGeometry(QRect(10, 80, 256, 192));
        txtName = new QLineEdit(PersonWindow);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(300, 40, 113, 24));
        txtDesc = new QLineEdit(PersonWindow);
        txtDesc->setObjectName("txtDesc");
        txtDesc->setGeometry(QRect(300, 90, 113, 24));
        txtLat = new QLineEdit(PersonWindow);
        txtLat->setObjectName("txtLat");
        txtLat->setGeometry(QRect(300, 140, 113, 24));
        txtLon = new QLineEdit(PersonWindow);
        txtLon->setObjectName("txtLon");
        txtLon->setGeometry(QRect(300, 190, 113, 24));
        txtDate = new QLineEdit(PersonWindow);
        txtDate->setObjectName("txtDate");
        txtDate->setGeometry(QRect(300, 230, 113, 24));
        btnAddEvent = new QPushButton(PersonWindow);
        btnAddEvent->setObjectName("btnAddEvent");
        btnAddEvent->setGeometry(QRect(310, 290, 80, 24));

        retranslateUi(PersonWindow);

        QMetaObject::connectSlotsByName(PersonWindow);
    } // setupUi

    void retranslateUi(QWidget *PersonWindow)
    {
        PersonWindow->setWindowTitle(QCoreApplication::translate("PersonWindow", "Form", nullptr));
        lblPosition->setText(QCoreApplication::translate("PersonWindow", "TextLabel", nullptr));
        chkNearby->setText(QCoreApplication::translate("PersonWindow", "CheckBox", nullptr));
        btnAddEvent->setText(QCoreApplication::translate("PersonWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonWindow: public Ui_PersonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONWINDOW_H
