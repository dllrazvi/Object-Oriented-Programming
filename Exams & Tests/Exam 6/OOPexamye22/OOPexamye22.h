#ifndef OOPEXAMYE22_H
#define OOPEXAMYE22_H

#include <QMainWindow>
#include "Person.h"
#include "Event.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class OOPexamye22; }
QT_END_NAMESPACE

class OOPexamye22 : public QMainWindow
{
    Q_OBJECT

public:
    OOPexamye22(QWidget* parent = nullptr);
    ~OOPexamye22();

private slots:
    void on_showPopularEventsButton_clicked();

private:
    Ui::OOPexamye22* ui;
    std::vector<Event> allEvents;
    std::vector<Person> allPersons;
};

#endif // OOPEXAMYE22_H
