#include "PopularEventsWindow.h"

PopularEventsWindow::PopularEventsWindow(const std::vector<Event>& events, QWidget* parent)
    : QWidget(parent), ui(new Ui::PopularEventsWindow) {
    ui->setupUi(this);

    for (const auto& event : events) {
        QString eventInfo = QString("%1 - %2 attendees").arg(event.getName()).arg(event.getAttendees().size());
        ui->popularEventsListWidget->addItem(new QListWidgetItem(eventInfo));
    }
}

PopularEventsWindow::~PopularEventsWindow() {
    delete ui;
}
