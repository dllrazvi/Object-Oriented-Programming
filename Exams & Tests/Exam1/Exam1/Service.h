#ifndef SERVICE_H
#define SERVICE_H

#include <vector>
#include <string>
#include "Domain.h"
#include "Repository.h"

class SchoolService {
public:
    SchoolService(SchoolRepository& repository);
    void addSchool(const std::string& name, double latitude, double longitude, const std::string& plannedVisitDate);
    void removeSchool(const std::string& name, double latitude, double longitude);
    std::vector<School> getAllSchools() const;
    std::vector<School> getSchoolsByPlannedVisitDate(const std::string& date) const;
    std::vector<School> getSchoolsByPlannedVisitDateAfter(const std::string& date) const;
    void markSchoolAsVisited(const std::string& name, double latitude, double longitude);

private:
    SchoolRepository& repository_;
};

#endif
