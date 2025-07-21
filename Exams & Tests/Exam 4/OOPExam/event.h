#pragma once
#include <string>
using namespace std;
class event
{
private:
	string organiser;
	string name;
	string description;
	int longitude;
	int latitude;
	string date;
public:
	event(string o, string n, string d, int lo, int la, string date) {
		this->organiser=o;
		this->name=n;
		this->description=d;
		this->longitude=lo;
		this->latitude=la;
		this->date=date;

	}
	string getOrganiser() const {
		return this->organiser;
	}
	string getName() const {
		return this->name;
	}
	string getDescription() const {
		return this->description;
	}
	int getLongitude() const {
		return this->longitude;
	}
	int getLatitude() const {
		return this->latitude;
	}
	string getDate() const {
		return this->date;
	}
	void setOrganiser(string o) {
		this->organiser=o;
	}
	void setName(string n) {
		this->name=n;
	}
	void setDescription(string d) {
		this->description=d;
	}
	void setLongitude(int lo) {
		this->longitude=lo;
	}
	void setLatitude(int la) {
		this->latitude=la;
	}
	void setDate(string date) {
		this->date=date;
	}
};