#include "service.h"
#include <algorithm>
#include <cmath>

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
std::vector<Event> Service::getNearbyEvents(const Person& person, double maxDistance)
{
    std::vector<Event> nearbyEvents;
    int personLatitude = person.getLatitude();
    int personLongitude = person.getLongitude();

    for (const auto& event : this->repo.getEvents())
    {
        int eventLatitude = event.getLatitude();
        int eventLongitude = event.getLongitude();

        // Calculate the distance between the person's location and the event's location
        double distance = std::sqrt(std::pow(eventLatitude - personLatitude, 2) + std::pow(eventLongitude - personLongitude, 2));

        // Check if the distance is within the maximum distance
        if (distance <= maxDistance)
        {
            nearbyEvents.push_back(event);
        }
    }

    return nearbyEvents;
}
std::vector<Event> Service::getEventsSorted()
{
	std::vector<Event> events = this->repo.getEvents();
	std::sort(events.begin(), events.end(), [](Event e1, Event e2) {return e1.getDate() < e2.getDate(); });
	return events;
}