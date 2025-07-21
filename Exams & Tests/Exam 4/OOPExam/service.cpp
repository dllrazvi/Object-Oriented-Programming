#include "service.h"

Service::Service()
{
    repo = repository();
}

vector<event> Service::getEvents()
{
    return repo.get_e_list();
}

vector<person> Service::getPersons()
{
    return repo.get_p_list();
}

vector<event> Service::getNearbyEvents(const person& p)
{
    vector<event> nearbyEvents;
    for (const auto& e : repo.get_e_list())
    {
        double distance = sqrt(pow(e.getLatitude() - p.get_latitude(), 2) + pow(e.getLongitude() - p.get_longitude(), 2));
        if (distance <= 5)
        {
            nearbyEvents.push_back(e);
        }
    }
    return nearbyEvents;
}

void Service::addEvent(const string& o, const string& n, const string& d, int la, int lo, const string& date)
{
    repo.add_event(o, n, d, la, lo, date);
    notifyObservers();
}

void Service::addPerson(const string& n, int la, int lo, int s)
{
    repo.add_person(n, la, lo, s);
    notifyObservers();
}

void Service::updateEventDescription(event& e, const string& newDescription)
{
    e.setDescription(newDescription);
    notifyObservers();
}

void Service::updateEventDate(event& e, const string& newDate)
{
    e.setDate(newDate);
    notifyObservers();
}

void Service::notifyObservers()
{
    for (Observer* observer : observers)
    {
        observer->update();
    }
}
