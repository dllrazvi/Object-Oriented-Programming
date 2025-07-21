#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exam.h"
#include "service.h"

class Exam : public QMainWindow
{
    Q_OBJECT

public:
    Exam(Service& s,Person p, QWidget *parent = nullptr);

private:
    Ui::ExamClass ui;
    Service& service;
    Person person;

    void populateList();
    void connect();
    void populateLocation();
    void handleAdd();
};
