#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QInputDialog>
#include "service.h"

class EventWindow : public QMainWindow, public Observer
{
private:
    Service& service;
    person personObj;

    QLabel* nameLabel;
    QLabel* locationLabel;
    QListWidget* eventsListWidget;
    QCheckBox* nearbyCheckBox;
    QPushButton* addButton;
    QTextEdit* descriptionTextEdit;
    QListWidget* attendeesListWidget;
    QTextEdit* eventDescriptionTextEdit;
    QPushButton* updateDescriptionButton;
    QTextEdit* eventDateTextEdit;
    QPushButton* updateDateButton;

public:
    EventWindow(Service& service, const person& personObj)
        : service(service), personObj(personObj)
    {
        service.registerObserver(this);
        initializeGUI();
        populateEventsList();
        setWindowTitle(QString::fromStdString(personObj.get_name()));
        updateLocationLabel();
        connectSignalsAndSlots();
    }

    void update() override
    {
        populateEventsList();
        updateAttendeesList();
        updateLocationLabel();
    }

private:
    void initializeGUI()
    {
        nameLabel = new QLabel(this);
        locationLabel = new QLabel(this);
        eventsListWidget = new QListWidget(this);
        nearbyCheckBox = new QCheckBox("Show Nearby Events", this);
        addButton = new QPushButton("Add Event", this);
        descriptionTextEdit = new QTextEdit(this);
        attendeesListWidget = new QListWidget(this);
        eventDescriptionTextEdit = new QTextEdit(this);
        updateDescriptionButton = new QPushButton("Update Description", this);
        eventDateTextEdit = new QTextEdit(this);
        updateDateButton = new QPushButton("Update Date", this);

        QVBoxLayout* mainLayout = new QVBoxLayout();
        QHBoxLayout* headerLayout = new QHBoxLayout();
        QVBoxLayout* eventsLayout = new QVBoxLayout();
        QVBoxLayout* attendeesLayout = new QVBoxLayout();
        QVBoxLayout* detailsLayout = new QVBoxLayout();

        nameLabel->setStyleSheet("font-size: 18pt; font-weight: bold;");
        locationLabel->setStyleSheet("font-size: 12pt;");

        headerLayout->addWidget(nameLabel);
        headerLayout->addWidget(locationLabel);

        eventsLayout->addWidget(eventsListWidget);
        eventsLayout->addWidget(nearbyCheckBox);
        eventsLayout->addWidget(addButton);

        attendeesLayout->addWidget(attendeesListWidget);

        detailsLayout->addWidget(descriptionTextEdit);
        detailsLayout->addWidget(attendeesListWidget);
        detailsLayout->addWidget(eventDescriptionTextEdit);
        detailsLayout->addWidget(updateDescriptionButton);
        detailsLayout->addWidget(eventDateTextEdit);
        detailsLayout->addWidget(updateDateButton);

        mainLayout->addLayout(headerLayout);
        mainLayout->addLayout(eventsLayout);
        mainLayout->addLayout(attendeesLayout);
        mainLayout->addLayout(detailsLayout);

        QWidget* centralWidget = new QWidget();
        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);
    }

    void connectSignalsAndSlots()
    {
        connect(addButton, &QPushButton::clicked, this, &EventWindow::addButtonClicked);
        connect(updateDescriptionButton, &QPushButton::clicked, this, &EventWindow::updateDescriptionButtonClicked);
        connect(updateDateButton, &QPushButton::clicked, this, &EventWindow::updateDateButtonClicked);
        connect(eventsListWidget, &QListWidget::currentItemChanged, this, &EventWindow::eventSelectionChanged);
        connect(nearbyCheckBox, &QCheckBox::stateChanged, this, &EventWindow::nearbyCheckBoxStateChanged);
    }

    void populateEventsList()
    {
        eventsListWidget->clear();
        vector<event> events = nearbyCheckBox->isChecked() ? service.getNearbyEvents(personObj) : service.getEvents();
        for (const auto& e : events)
        {
            QString eventText = QString::fromStdString(e.getName()) + " - " + QString::fromStdString(e.getDate());
            QListWidgetItem* item = new QListWidgetItem(eventText, eventsListWidget);
            item->setData(Qt::UserRole, QVariant::fromValue(e));
            if (e.getOrganiser() == personObj.get_name())
            {
                item->setBackground(QBrush(Qt::green));
            }
        }
    }

    void updateAttendeesList()
    {
        attendeesListWidget->clear();
        QListWidgetItem* item = new QListWidgetItem("Attendees:", attendeesListWidget);
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
        item->setForeground(Qt::gray);
        event selectedItem = getSelectedEvent();
        if (selectedItem.getName() != "")
        {
            for (const auto& p : service.getPersons())
            {
                if (p.get_name() != personObj.get_name())
                {
                    QListWidgetItem* attendeeItem = new QListWidgetItem(QString::fromStdString(p.get_name()), attendeesListWidget);
                    attendeeItem->setFlags(attendeeItem->flags() & ~Qt::ItemIsSelectable);
                    if (isSelectedAttendee(p, selectedItem))
                    {
                        attendeeItem->setCheckState(Qt::Checked);
                        if (p.get_status())
                        {
                            attendeeItem->setBackground(QBrush(Qt::green));
                        }
                    }
                    else
                    {
                        attendeeItem->setCheckState(Qt::Unchecked);
                    }
                }
            }
        }
    }

    void updateLocationLabel()
    {
        QString locationText = "Location: (" + QString::number(personObj.get_latitude()) + ", " + QString::number(personObj.get_longitude()) + ")";
        locationLabel->setText(locationText);
    }

    event getSelectedEvent()
    {
        QListWidgetItem* selectedItem = eventsListWidget->currentItem();
        if (selectedItem != nullptr)
        {
            return selectedItem->data(Qt::UserRole).value<event>();
        }
        return event("", "", "", 0, 0, "");
    }

    bool isSelectedAttendee(const person& p, const event& e)
    {
        for (const auto& attendee : e.getAttendees())
        {
            if (attendee.get_name() == p.get_name())
            {
                return true;
            }
        }
        return false;
    }

private slots:
    void addButtonClicked()
    {
        QString name = QInputDialog::getText(this, "Add Event", "Name:");
        QString description = QInputDialog::getText(this, "Add Event", "Description:");
        QString latitude = QInputDialog::getText(this, "Add Event", "Latitude:");
        QString longitude = QInputDialog::getText(this, "Add Event", "Longitude:");
        QString date = QInputDialog::getText(this, "Add Event", "Date:");

        service.addEvent(personObj.get_name(), name.toStdString(), description.toStdString(), latitude.toInt(), longitude.toInt(), date.toStdString());
    }

    void updateDescriptionButtonClicked()
    {
        event selectedItem = getSelectedEvent();
        if (selectedItem.getName() != "")
        {
            QString newDescription = QInputDialog::getText(this, "Update Description", "New Description:");
            service.updateEventDescription(selectedItem, newDescription.toStdString());
        }
    }

    void updateDateButtonClicked()
    {
        event selectedItem = getSelectedEvent();
        if (selectedItem.getName() != "")
        {
            QString newDate = QInputDialog::getText(this, "Update Date", "New Date:");
            service.updateEventDate(selectedItem, newDate.toStdString());
        }
    }

    void eventSelectionChanged()
    {
        event selectedItem = getSelectedEvent();
        if (selectedItem.getName() != "")
        {
            descriptionTextEdit->setPlainText(QString::fromStdString(selectedItem.getDescription()));
            updateAttendeesList();
            eventDescriptionTextEdit->setPlainText(QString::fromStdString(selectedItem.getDescription()));
            eventDateTextEdit->setPlainText(QString::fromStdString(selectedItem.getDate()));
        }
    }

    void nearbyCheckBoxStateChanged()
    {
        populateEventsList();
    }
};

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Service service;

    vector<person> persons = service.getPersons();
    vector<EventWindow*> eventWindows;

    for (const auto& p : persons)
    {
        EventWindow* eventWindow = new EventWindow(service, p);
        eventWindow->show();
        eventWindows.push_back(eventWindow);
    }

    return a.exec();
}
