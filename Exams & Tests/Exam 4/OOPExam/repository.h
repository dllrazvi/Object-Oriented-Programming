#pragma once
using namespace std;
#include <vector>
#include "event.h"
#include "person.h"

class repository
{
private:
	vector<event>EList;
	vector<person>PList;
	void read_E_from_file();
	void read_P_from_file();
	void write_E_to_file();
	void write_P_to_file();

public:
	repository() {
		read_E_from_file();
		read_P_from_file();
	}
	void add_event(string o, string n, string d, int la, int lo, string date);
	void add_person(string n, int la, int lo, int s);
	vector<event>& get_e_list() { return this->EList; }
	vector<person>& get_p_list() { return this->PList; }
	~repository() {}
};