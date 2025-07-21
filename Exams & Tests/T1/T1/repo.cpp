#include "repo.h"

bool SchoolRepo::addSchool(const School& school) {
    for (const auto& s : schools) {
        if (s.getName() == school.getName() &&
            s.getLatitude() == school.getLatitude() &&
            s.getLongitude() == school.getLongitude()) {
            return false;
        }
    }
    schools.push_back(school);
    return true;
}

const std::vector<School>& SchoolRepo::getAll() const {
    return schools;
}
