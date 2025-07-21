#pragma once
#include <iostream>
#include <string>
#include <vector>
class Event
{
private:
	std::string organizer;
	std::string name;
	std::string description;
	int latitude;
	int longitude;
	std::string date;
public:
	Event();
	Event(std::string organizer, std::string name, std::string description, int latitude, int longitude, std::string date);

	std::string getOrganizer()  { return organizer; }
	std::string getName() { return name; }
	std::string getDescription() { return description; }
	int getLatitude() { return latitude; }
	int getLongitude() { return longitude; }
	std::string getDate() { return date; }

	std::string toString();

	friend std::istream& operator>>(std::istream& is, Event& e);
	friend std::ostream& operator<<(std::ostream& os, Event& e);

};


