#ifndef VOLUNTEERSERVICE_H
#define VOLUNTEERSERVICE_H

#include "VolunteerRepository.h"
#include <vector>
#include <algorithm>

class VolunteerService {
private:
    VolunteerRepository& repo;

public:
    VolunteerService(VolunteerRepository& repo);
    void addVolunteer(const Volunteer& volunteer);
    std::vector<Volunteer> getVolunteersByDepartment(const QString& departmentName) const;
    std::vector<Volunteer> getUnassignedVolunteers() const;
};

#endif // VOLUNTEERSERVICE_H
