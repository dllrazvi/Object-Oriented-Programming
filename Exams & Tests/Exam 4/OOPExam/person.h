#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class person
{
private:
	string name;
	int latitude;
	int longitude;
	int status;
	
public:
	person(string name, int latitude, int longitude, int status) {
		this->name=name;
		this->latitude=latitude;
		this->longitude=longitude;
		this->status=status;
	}
	string get_name() const{
		return this->name;
	}
	int get_latitude() const {
		return this->latitude;
	}
	int get_longitude() const {
		return this->longitude;
	}
	bool get_status() const {
		return this->status;
	}
	void set_name(char* name) {
		this->name=name;
	}
	void set_latitude(int latitude) {
		this->latitude=latitude;
	}
	void set_longitude(int longitude) {
		this->longitude=longitude;
	}
	void set_status(bool status) {
		this->status=status;
	}
	~person();
};