#pragma once
#include <QWidget>
#include "Service.h"
#include "ui_PersonWindow.h"

class PersonWindow : public QWidget
{
    Q_OBJECT
public:
    PersonWindow(const Person& p, Service& srv, QWidget* parent = nullptr);
    ~PersonWindow();

private:               
    Ui::PersonWindow* ui;
    const Person      person;
    Service& service;

private:               
    void reloadEventList();     
    bool readEventFromFields(Event& outEv); 

private slots:         
    void onCheckboxChanged(int);         
    void onAddEventClicked();               
};
