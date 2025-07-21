#include "service.h"
#include <algorithm>

void Service::addEvent(std::string organiser, std::string name, std::string description, int latitute, int longitude, std::string date)
{
	Event e{ organiser, name, description, latitute, longitude, date };
	this->repo.addEvent(e);
}

void Service::addPerson(std::string name, int latitute, int longitude, bool status)
{
	Person p{ name, latitute, longitude, status };
	this->repo.addPerson(p);
}

std::vector<Event> Service::getEventsSorted()
{
	std::vector<Event> events = this->repo.getEvents();
	std::sort(events.begin(), events.end(), [](Event e1, Event e2) {return e1.getDate() < e2.getDate(); });
	return events;
}#include "service.h"
#include <algorithm>

void Service::addEvent(std::string organiser, std::string name, std::string description, int latitute, int longitude, std::string date)
{
	Event e{ organiser, name, description, latitute, longitude, date };
	this->repo.addEvent(e);
}

void Service::addPerson(std::string name, int latitute, int longitude, bool status)
{
	Person p{ name, latitute, longitude, status };
	this->repo.addPerson(p);
}

std::vector<Event> Service::getEventsSorted()
{
	std::vector<Event> events = this->repo.getEvents();
	std::sort(events.begin(), events.end(), [](Event e1, Event e2) {return e1.getDate() < e2.getDate(); });
	return events;
}