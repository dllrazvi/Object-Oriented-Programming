#ifndef SCHOOL_SERVICE_H
#define SCHOOL_SERVICE_H

#include "repo.h"
#include <vector>

class SchoolService {
private:
    SchoolRepo& repo;

public:
    SchoolService(SchoolRepo& repo);

    bool addSchool(const std::string& name, double lat, double lon, const std::string& date);
    std::vector<School> getAllSchools() const;
    std::vector<School> getClosestSchools(double lat, double lon, int n = 3) const;
};

#endif