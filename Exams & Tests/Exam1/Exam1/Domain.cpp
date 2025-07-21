#include "Domain.h"
using namespace std;
School::School(const string& name, double latitude, double longitude,
    chrono::system_clock::time_point plannedVisitDate, bool visited)
    : name{ name }, latitude{ latitude }, longitude{ longitude },
    plannedVisitDate{ plannedVisitDate }, visited{ visited } {}

string School::getName() const {
    return name;
}

double School::getLatitude() const {
    return latitude;
}

double School::getLongitude() const {
    return longitude;
}

chrono::system_clock::time_point School::getPlannedVisitDate() const {
    return plannedVisitDate;
}

bool School::isVisited() const {
    return visited;
}

void School::setVisited(bool visited) {
    this->visited = visited;
}
