#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPExam.h"

class OOPExam : public QMainWindow
{
    Q_OBJECT

public:
    OOPExam(QWidget *parent = nullptr);
    ~OOPExam();

private:
    Ui::OOPExamClass ui;
};
