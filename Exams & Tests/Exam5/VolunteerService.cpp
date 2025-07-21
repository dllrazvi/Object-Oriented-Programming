#include "VolunteerService.h"

VolunteerService::VolunteerService(VolunteerRepository& repo) : repo(repo) {}

void VolunteerService::addVolunteer(const Volunteer& volunteer) {
    // Here, you might want to check for duplicates or validate data before adding
    repo.getVolunteers().push_back(volunteer);
}

std::vector<Volunteer> VolunteerService::getVolunteersByDepartment(const QString& departmentName) const {
    std::vector<Volunteer> result;
    const auto& volunteers = repo.getVolunteers();
    std::copy_if(volunteers.begin(), volunteers.end(), std::back_inserter(result),
        [&departmentName](const Volunteer& v) { return v.department == departmentName; });
    return result;
}

std::vector<Volunteer> VolunteerService::getUnassignedVolunteers() const {
    std::vector<Volunteer> result;
    const auto& volunteers = repo.getVolunteers();
    std::copy_if(volunteers.begin(), volunteers.end(), std::back_inserter(result),
        [](const Volunteer& v) { return v.department.isEmpty(); });
    return result;
}
