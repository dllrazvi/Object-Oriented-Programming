/********************************************************************************
** Form generated from reading UI file 'Exam.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamClass
{
public:
    QWidget *centralWidget;
    QListWidget *eventsWidget;
    QListWidget *latitudeWidget;
    QListWidget *longitudeWidget;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamClass)
    {
        if (ExamClass->objectName().isEmpty())
            ExamClass->setObjectName("ExamClass");
        ExamClass->resize(854, 524);
        centralWidget = new QWidget(ExamClass);
        centralWidget->setObjectName("centralWidget");
        eventsWidget = new QListWidget(centralWidget);
        eventsWidget->setObjectName("eventsWidget");
        eventsWidget->setGeometry(QRect(10, 0, 321, 251));
        latitudeWidget = new QListWidget(centralWidget);
        latitudeWidget->setObjectName("latitudeWidget");
        latitudeWidget->setGeometry(QRect(420, 0, 81, 21));
        longitudeWidget = new QListWidget(centralWidget);
        longitudeWidget->setObjectName("longitudeWidget");
        longitudeWidget->setGeometry(QRect(420, 30, 81, 21));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 0, 49, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 30, 49, 16));
        ExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExamClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 854, 22));
        ExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamClass);
        mainToolBar->setObjectName("mainToolBar");
        ExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExamClass);
        statusBar->setObjectName("statusBar");
        ExamClass->setStatusBar(statusBar);

        retranslateUi(ExamClass);

        QMetaObject::connectSlotsByName(ExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamClass)
    {
        ExamClass->setWindowTitle(QCoreApplication::translate("ExamClass", "Exam", nullptr));
        label->setText(QCoreApplication::translate("ExamClass", "Lat", nullptr));
        label_2->setText(QCoreApplication::translate("ExamClass", "Lon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamClass: public Ui_ExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
