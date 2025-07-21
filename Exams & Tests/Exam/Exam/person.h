#pragma once
#include <iostream>
#include <string>
#include <vector>
class Person
{
private:
	std::string name;
	int latitude;
	int longitude;
	bool status;
public:
	Person();
	Person(std::string name, int latitude, int longitude, bool status);

	std::string getName() { return name; }
	int getLatitude() { return latitude; }
	int getLongitude() { return longitude; }
	bool getStatus() { return status; }

	std::string toString();

	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	friend std::istream& operator>>(std::istream& is, Person& p);
};

