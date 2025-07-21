#include "VolunteerRepository.h"
#include <fstream>
#include <sstream>

void VolunteerRepository::loadFromFile(const QString& filename) {
    std::ifstream file(filename.toStdString());
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, email, interestsStr, department;
        std::getline(iss, name, ';');
        std::getline(iss, email, ';');
        std::getline(iss, interestsStr, ';');
        std::getline(iss, department, ';');
        QStringList interests = QString::fromStdString(interestsStr).split('|', Qt::SkipEmptyParts);
        volunteers.emplace_back(QString::fromStdString(name), QString::fromStdString(email), interests, QString::fromStdString(department));
    }
}

std::vector<Volunteer>& VolunteerRepository::getVolunteers() {
    return volunteers;
}
