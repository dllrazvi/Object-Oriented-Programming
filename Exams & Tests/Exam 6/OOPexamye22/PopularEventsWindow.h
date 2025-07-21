#ifndef POPULAREVENTSWINDOW_H
#define POPULAREVENTSWINDOW_H

#include <QWidget>
#include "Event.h"
#include <vector>

namespace Ui {
    class PopularEventsWindow;
}

class PopularEventsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PopularEventsWindow(const std::vector<Event>& events, QWidget* parent = nullptr);
    ~PopularEventsWindow();

private:
    Ui::PopularEventsWindow* ui;
    void displayPopularEvents(const std::vector<Event>& events);
};

#endif // POPULAREVENTSWINDOW_H
