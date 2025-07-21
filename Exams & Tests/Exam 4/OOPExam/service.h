#pragma once
#include "repository.h"
#include "subject.h" // Include the header file for the Subject class

class Service : public Subject
{
private:
    repository repo;
    vector<Observer*> observers;

public:
    Service();
    vector<event> getEvents();
    vector<person> getPersons();
    vector<event> getNearbyEvents(const person& p);
    void addEvent(const string& o, const string& n, const string& d, int la, int lo, const string& date);
    void addPerson(const string& n, int la, int lo, int s);
    void updateEventDescription(event& e, const string& newDescription);
    void updateEventDate(event& e, const string& newDate);
    void notifyObservers();
};
