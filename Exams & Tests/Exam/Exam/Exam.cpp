#include "Exam.h"

Exam::Exam(Service& s,Person p, QWidget *parent)
    :service{ s }, person{p}, QMainWindow(parent)
{
    ui.setupUi(this);
    this->populateList();
   // this->populateLocation();
}

void Exam::populateList()
{
	this->ui.eventsWidget->clear();
    std::vector<Event> events = this->service.getEventsSorted();
	for (auto& event : events)
	{
		if(event.getOrganizer()==this->person.getName())
		{
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(event.toString()));
			item->setBackground(Qt::green);
			this->ui.eventsWidget->addItem(item);
		}
		else
		{
			QString itemInList = QString::fromStdString(event.toString());
			this->ui.eventsWidget->addItem(itemInList);
		}
	}
}

void Exam::populateLocation()
{
	this->ui.latitudeWidget->clear();
	this->ui.longitudeWidget->clear();

	this->ui.latitudeWidget->addItem(QString::fromStdString(std::to_string(this->person.getLatitude())));
	this->ui.longitudeWidget->addItem(QString::fromStdString(std::to_string(this->person.getLongitude())));
}

