#include "PersonWindow.h"
#include "ui_PersonWindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QListWidgetItem>

PersonWindow::PersonWindow(const Person& person, const std::vector<Event>& events, QWidget* parent)
    : QWidget(parent), ui(new Ui::PersonWindow) {
    ui->setupUi(this);
    displayPersonInfo(person, events);
}

PersonWindow::~PersonWindow() {
    delete ui;
}

void PersonWindow::displayPersonInfo(const Person& person, const std::vector<Event>& events) {
    QString personInfo = QString("%1, %2, %3")
        .arg(person.getName())
        .arg(person.getLatitude())
        .arg(person.getLongitude());
    ui->personInfoLabel->setText(personInfo);

    for (const auto& event : events) {
        QString eventInfo = QString("%1, %2, %3, %4")
            .arg(event.getName())
            .arg(event.getLatitude())
            .arg(event.getLongitude())
            .arg(event.getDate());

        QListWidgetItem* item = new QListWidgetItem(eventInfo);
        if (event.getOrganizer() == person.getName()) {
            item->setBackgroundColor(Qt::green);
        }
        ui->eventsListWidget->addItem(item);
    }
}

void PersonWindow::on_showNearbyEventsOnlyCheckbox_toggled(bool checked) {
    // Implement the functionality to show only nearby events
}

void PersonWindow::on_addEventButton_clicked() {
    bool ok;
    QString name = QInputDialog::getText(this, "Event Name", "Enter event name:", QLineEdit::Normal, QString(), &ok);
    if (!ok) return;

    QString description = QInputDialog::getText(this, "Event Description", "Enter event description:", QLineEdit::Normal, QString(), &ok);
    if (!ok) return;

    double latitude = QInputDialog::getDouble(this, "Event Latitude", "Enter event latitude:", 0, -90, 90, 6, &ok);
    if (!ok) return;

    double longitude = QInputDialog::getDouble(this, "Event Longitude", "Enter event longitude:", 0, -180, 180, 6, &ok);
    if (!ok) return;

    QString date = QInputDialog::getText(this, "Event Date", "Enter event date (YYYY-MM-DD):", QLineEdit::Normal, QString(), &ok);
    if (!ok) return;

    // Create the event and add it to the service
}

void PersonWindow::on_markAttendanceButton_clicked() {
    // Implement the functionality to mark attendance
}

void PersonWindow::on_eventsListWidget_itemClicked(QListWidgetItem* item) {
    // Implement the functionality to show event details
}
