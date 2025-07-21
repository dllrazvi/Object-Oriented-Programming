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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QListWidget *eventsListWidgetlabel;
    QLabel *locationLabel;
    QCheckBox *nearbyEventsCheckbox;
    QPushButton *addEventButton;
    QPushButton *markAttendanceButton;
    QLabel *eventDescriptionLabel;
    QPushButton *updateEventButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 300);
        eventsListWidgetlabel = new QListWidget(Form);
        eventsListWidgetlabel->setObjectName("eventsListWidgetlabel");
        eventsListWidgetlabel->setGeometry(QRect(30, 20, 256, 192));
        locationLabel = new QLabel(Form);
        locationLabel->setObjectName("locationLabel");
        locationLabel->setGeometry(QRect(40, 240, 191, 16));
        nearbyEventsCheckbox = new QCheckBox(Form);
        nearbyEventsCheckbox->setObjectName("nearbyEventsCheckbox");
        nearbyEventsCheckbox->setGeometry(QRect(40, 270, 75, 20));
        addEventButton = new QPushButton(Form);
        addEventButton->setObjectName("addEventButton");
        addEventButton->setGeometry(QRect(160, 260, 75, 24));
        markAttendanceButton = new QPushButton(Form);
        markAttendanceButton->setObjectName("markAttendanceButton");
        markAttendanceButton->setGeometry(QRect(170, 220, 121, 24));
        eventDescriptionLabel = new QLabel(Form);
        eventDescriptionLabel->setObjectName("eventDescriptionLabel");
        eventDescriptionLabel->setGeometry(QRect(250, 270, 121, 20));
        updateEventButton = new QPushButton(Form);
        updateEventButton->setObjectName("updateEventButton");
        updateEventButton->setGeometry(QRect(310, 220, 75, 24));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        locationLabel->setText(QCoreApplication::translate("Form", "Location", nullptr));
        nearbyEventsCheckbox->setText(QCoreApplication::translate("Form", "CheckBox", nullptr));
        addEventButton->setText(QCoreApplication::translate("Form", "Add event", nullptr));
        markAttendanceButton->setText(QCoreApplication::translate("Form", "Mark attendence", nullptr));
        eventDescriptionLabel->setText(QCoreApplication::translate("Form", "Description event", nullptr));
        updateEventButton->setText(QCoreApplication::translate("Form", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONWINDOW_H
