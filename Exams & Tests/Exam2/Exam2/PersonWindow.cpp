#include "PersonWindow.h"
#include "ui_PersonWindow.h"

#include <QMessageBox>
#include <QDate>
#include <algorithm>
#include <sstream>

PersonWindow::PersonWindow(const Person& p, Service& srv, QWidget* parent)
    : QWidget(parent), ui(new Ui::PersonWindow), person(p), service(srv)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(person.getName()));

    ui->lblPosition->setText(
        "Location: (" + QString::number(person.getLat()) + ", "
        + QString::number(person.getLon()) + ")");
    connect(ui->chkNearby, &QCheckBox::stateChanged,
        this, &PersonWindow::onCheckboxChanged);
    connect(ui->btnAddEvent, &QPushButton::clicked,
        this, &PersonWindow::onAddEventClicked);


    reloadEventList();
}

PersonWindow::~PersonWindow() { delete ui; }


void PersonWindow::reloadEventList()
{
    ui->listEvents->clear();

    std::vector<Event> events;
    if (ui->chkNearby->isChecked())
        events = service.getEventsNear(person.getLat(), person.getLon(), 5.0);
    else
        events = service.getEvents();

    std::sort(events.begin(), events.end(),
        [](const Event& a, const Event& b) { return a.getDate() < b.getDate(); });

    for (const auto& ev : events)
    {
        std::ostringstream os;
        os << ev.getName() << "  "
            << ev.getLat() << "," << ev.getLon() << "  "
            << ev.getDate() << "  | "
            << ev.getAttendees().size() << " going";

        auto* itm = new QListWidgetItem(QString::fromStdString(os.str()));

        if (ev.getOrganiser() == person.getName())   
            itm->setBackground(QColor(180, 255, 180));

        ui->listEvents->addItem(itm);
    }
}

void PersonWindow::onCheckboxChanged(int)
{
    reloadEventList();
}

void PersonWindow::onAddEventClicked()
{
    Event newEv("", "", "", 0, 0, "");      // placeholder
    if (!readEventFromFields(newEv))
        return;                            

    try {
        service.addEvent(newEv);
        reloadEventList();
        QMessageBox::information(this, "Success", "Event added!");
        ui->txtName->clear();
        ui->txtDesc->clear();
        ui->txtLat->clear();
        ui->txtLon->clear();
        ui->txtDate->clear();
    }
    catch (const std::exception& ex) {
        QMessageBox::warning(this, "Add event failed", ex.what());
    }
}

bool PersonWindow::readEventFromFields(Event& outEv)
{
    QString qn = ui->txtName->text().trimmed();
    QString qd = ui->txtDesc->text().trimmed();
    QString qla = ui->txtLat->text().trimmed();
    QString qlo = ui->txtLon->text().trimmed();
    QString qdt = ui->txtDate->text().trimmed();           // YYYY-MM-DD

    if (qn.isEmpty() || qd.isEmpty() || qla.isEmpty()
        || qlo.isEmpty() || qdt.isEmpty()) {
        QMessageBox::warning(this, "Validation",
            "All fields must be completed!");
        return false;
    }
    bool okLat = false, okLon = false;
    double lat = qla.toDouble(&okLat);
    double lon = qlo.toDouble(&okLon);
    if (!okLat || !okLon) {
        QMessageBox::warning(this, "Validation",
            "Latitude / Longitude must be numbers!");
        return false;
    }
 
    QDate dd = QDate::fromString(qdt, "yyyy-MM-dd");
    if (!dd.isValid()) {
        QMessageBox::warning(this, "Validation", "Date must be YYYY-MM-DD!");
        return false;
    }

    outEv = Event(
        person.getName(),               
        qn.toStdString(),
        qd.toStdString(),
        lat, lon,
        qdt.toStdString()
    );
    return true;
}
