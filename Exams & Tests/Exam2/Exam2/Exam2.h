#pragma once
#include <QMainWindow>
#include "ui_Exam2.h"
#include "Service.h"

class Exam2 : public QMainWindow {
    Q_OBJECT
public:
    Exam2(Service& srv, QWidget* parent = nullptr);
    ~Exam2();
private:
    Ui::Exam2* ui;
    Service& service;

    void loadPersonList();
    void openPersonWindow();
};
