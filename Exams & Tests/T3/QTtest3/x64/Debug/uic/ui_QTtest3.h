/********************************************************************************
** Form generated from reading UI file 'QTtest3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTEST3_H
#define UI_QTTEST3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTtest3Class
{
public:
    QWidget *centralWidget;
    QListWidget *sessionList;
    QLineEdit *startTimeInput;
    QLabel *totalHoursLabel;
    QPushButton *showIntervalsButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *intensityInput;
    QLineEdit *typeInput;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *filterButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTtest3Class)
    {
        if (QTtest3Class->objectName().isEmpty())
            QTtest3Class->setObjectName("QTtest3Class");
        QTtest3Class->resize(600, 400);
        centralWidget = new QWidget(QTtest3Class);
        centralWidget->setObjectName("centralWidget");
        sessionList = new QListWidget(centralWidget);
        sessionList->setObjectName("sessionList");
        sessionList->setGeometry(QRect(300, 0, 291, 211));
        startTimeInput = new QLineEdit(centralWidget);
        startTimeInput->setObjectName("startTimeInput");
        startTimeInput->setGeometry(QRect(30, 80, 131, 21));
        totalHoursLabel = new QLabel(centralWidget);
        totalHoursLabel->setObjectName("totalHoursLabel");
        totalHoursLabel->setGeometry(QRect(40, 130, 201, 121));
        showIntervalsButton = new QPushButton(centralWidget);
        showIntervalsButton->setObjectName("showIntervalsButton");
        showIntervalsButton->setGeometry(QRect(304, 270, 161, 24));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 20, 134, 50));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        intensityInput = new QLineEdit(widget);
        intensityInput->setObjectName("intensityInput");

        verticalLayout->addWidget(intensityInput);

        typeInput = new QLineEdit(widget);
        typeInput->setObjectName("typeInput");

        verticalLayout->addWidget(typeInput);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(90, 270, 207, 26));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        filterButton = new QPushButton(widget1);
        filterButton->setObjectName("filterButton");

        horizontalLayout->addWidget(filterButton);

        QTtest3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTtest3Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        QTtest3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTtest3Class);
        mainToolBar->setObjectName("mainToolBar");
        QTtest3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTtest3Class);
        statusBar->setObjectName("statusBar");
        QTtest3Class->setStatusBar(statusBar);

        retranslateUi(QTtest3Class);

        QMetaObject::connectSlotsByName(QTtest3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QTtest3Class)
    {
        QTtest3Class->setWindowTitle(QCoreApplication::translate("QTtest3Class", "QTtest3", nullptr));
        startTimeInput->setText(QCoreApplication::translate("QTtest3Class", "Intervals Input", nullptr));
        totalHoursLabel->setText(QCoreApplication::translate("QTtest3Class", "Total Hours", nullptr));
        showIntervalsButton->setText(QCoreApplication::translate("QTtest3Class", "show Intervals Button", nullptr));
        intensityInput->setText(QCoreApplication::translate("QTtest3Class", "Intensity Input", nullptr));
        typeInput->setText(QCoreApplication::translate("QTtest3Class", "Type Input", nullptr));
        filterButton->setText(QCoreApplication::translate("QTtest3Class", "Filter Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTtest3Class: public Ui_QTtest3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTEST3_H
