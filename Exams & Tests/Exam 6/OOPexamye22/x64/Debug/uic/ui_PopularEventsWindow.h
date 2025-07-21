/********************************************************************************
** Form generated from reading UI file 'PopularEventsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPULAREVENTSWINDOW_H
#define UI_POPULAREVENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopularEventsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *popularEventsListWidget;

    void setupUi(QWidget *PopularEventsWindow)
    {
        if (PopularEventsWindow->objectName().isEmpty())
            PopularEventsWindow->setObjectName("PopularEventsWindow");
        PopularEventsWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(PopularEventsWindow);
        verticalLayout->setObjectName("verticalLayout");
        popularEventsListWidget = new QListWidget(PopularEventsWindow);
        popularEventsListWidget->setObjectName("popularEventsListWidget");

        verticalLayout->addWidget(popularEventsListWidget);


        retranslateUi(PopularEventsWindow);

        QMetaObject::connectSlotsByName(PopularEventsWindow);
    } // setupUi

    void retranslateUi(QWidget *PopularEventsWindow)
    {
        PopularEventsWindow->setWindowTitle(QCoreApplication::translate("PopularEventsWindow", "Popular Events", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PopularEventsWindow: public Ui_PopularEventsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPULAREVENTSWINDOW_H
