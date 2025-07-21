#ifndef VOLUNTEERREPOSITORY_H
#define VOLUNTEERREPOSITORY_H

#include "Volunteer.h"
#include <vector>

class VolunteerRepository {
private:
    std::vector<Volunteer> volunteers;

public:
    void loadFromFile(const QString& filename);
    std::vector<Volunteer>& getVolunteers();
};

#endif // VOLUNTEERREPOSITORY_H
