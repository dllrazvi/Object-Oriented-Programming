/********************************************************************************
** Form generated from reading UI file 'OOPExam.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPEXAM_H
#define UI_OOPEXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OOPExamClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOPExamClass)
    {
        if (OOPExamClass->objectName().isEmpty())
            OOPExamClass->setObjectName("OOPExamClass");
        OOPExamClass->resize(600, 400);
        menuBar = new QMenuBar(OOPExamClass);
        menuBar->setObjectName("menuBar");
        OOPExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOPExamClass);
        mainToolBar->setObjectName("mainToolBar");
        OOPExamClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OOPExamClass);
        centralWidget->setObjectName("centralWidget");
        OOPExamClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OOPExamClass);
        statusBar->setObjectName("statusBar");
        OOPExamClass->setStatusBar(statusBar);

        retranslateUi(OOPExamClass);

        QMetaObject::connectSlotsByName(OOPExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *OOPExamClass)
    {
        OOPExamClass->setWindowTitle(QCoreApplication::translate("OOPExamClass", "OOPExam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPExamClass: public Ui_OOPExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPEXAM_H
