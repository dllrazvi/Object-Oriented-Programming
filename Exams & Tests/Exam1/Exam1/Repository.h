#pragma once
#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP
using namespace std;
#include "Domain.h"
#include <vector>

class SchoolRepository {
public:
    virtual void addSchool(const School& school) = 0;
    virtual void removeSchool(const string& name, double latitude, double longitude) = 0;
    virtual vector<School> getAllSchools() const = 0;
    virtual vector<School> getSchoolsByPlannedVisitDate(const std::chrono::system_clock::time_point& date) const = 0;
};

#endif // REPOSITORY_HPP
