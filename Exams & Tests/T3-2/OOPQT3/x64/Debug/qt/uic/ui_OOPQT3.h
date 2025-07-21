/********************************************************************************
** Form generated from reading UI file 'OOPQT3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPQT3_H
#define UI_OOPQT3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_OOPQT3Class
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *bestMatchButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOPQT3Class)
    {
        if (OOPQT3Class->objectName().isEmpty())
            OOPQT3Class->setObjectName("OOPQT3Class");
        OOPQT3Class->resize(600, 400);
        centralWidget = new QWidget(OOPQT3Class);
        centralWidget->setObjectName("centralWidget");
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 10, 258, 256));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        searchLineEdit = new QLineEdit(layoutWidget);
        searchLineEdit->setObjectName("searchLineEdit");

        verticalLayout->addWidget(searchLineEdit);

        bestMatchButton = new QPushButton(layoutWidget);
        bestMatchButton->setObjectName("bestMatchButton");

        verticalLayout->addWidget(bestMatchButton);


        verticalLayout_2->addLayout(verticalLayout);

        OOPQT3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OOPQT3Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        OOPQT3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOPQT3Class);
        mainToolBar->setObjectName("mainToolBar");
        OOPQT3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OOPQT3Class);
        statusBar->setObjectName("statusBar");
        OOPQT3Class->setStatusBar(statusBar);

        retranslateUi(OOPQT3Class);

        QMetaObject::connectSlotsByName(OOPQT3Class);
    } // setupUi

    void retranslateUi(QMainWindow *OOPQT3Class)
    {
        OOPQT3Class->setWindowTitle(QCoreApplication::translate("OOPQT3Class", "OOPQT3", nullptr));
        bestMatchButton->setText(QCoreApplication::translate("OOPQT3Class", "Show best matching", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPQT3Class: public Ui_OOPQT3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPQT3_H
