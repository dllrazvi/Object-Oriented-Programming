#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QWidget>
#include "Person.h"
#include "Event.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PersonWindow; }
QT_END_NAMESPACE

class PersonWindow : public QWidget {
    Q_OBJECT

public:
    PersonWindow(const Person& person, const std::vector<Event>& events, QWidget* parent = nullptr);
    ~PersonWindow();

private:
    Ui::PersonWindow* ui;
    void displayPersonInfo(const Person& person, const std::vector<Event>& events);

private slots:
    void on_showNearbyEventsOnlyCheckbox_toggled(bool checked);
    void on_addEventButton_clicked();
    void on_markAttendanceButton_clicked();
    void on_eventsListWidget_itemClicked(QListWidgetItem* item);
};

#endif // PERSONWINDOW_H
