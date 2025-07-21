/********************************************************************************
** Form generated from reading UI file 'Exam2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM2_H
#define UI_EXAM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exam2
{
public:
    QWidget *centralWidget;
    QListWidget *listPersons;
    QPushButton *btnOpenPerson;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Exam2)
    {
        if (Exam2->objectName().isEmpty())
            Exam2->setObjectName("Exam2");
        Exam2->resize(600, 400);
        centralWidget = new QWidget(Exam2);
        centralWidget->setObjectName("centralWidget");
        listPersons = new QListWidget(centralWidget);
        listPersons->setObjectName("listPersons");
        listPersons->setGeometry(QRect(100, 60, 256, 192));
        btnOpenPerson = new QPushButton(centralWidget);
        btnOpenPerson->setObjectName("btnOpenPerson");
        btnOpenPerson->setGeometry(QRect(100, 270, 80, 24));
        Exam2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Exam2);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Exam2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Exam2);
        mainToolBar->setObjectName("mainToolBar");
        Exam2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Exam2);
        statusBar->setObjectName("statusBar");
        Exam2->setStatusBar(statusBar);

        retranslateUi(Exam2);

        QMetaObject::connectSlotsByName(Exam2);
    } // setupUi

    void retranslateUi(QMainWindow *Exam2)
    {
        Exam2->setWindowTitle(QCoreApplication::translate("Exam2", "Exam2", nullptr));
        btnOpenPerson->setText(QCoreApplication::translate("Exam2", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exam2: public Ui_Exam2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM2_H
