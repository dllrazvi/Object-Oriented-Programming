#include "Repository.h"
#include <algorithm>
#include <iostream>
using namespace std;
class InMemorySchoolRepository : public SchoolRepository {
private:
    std::vector<School> schools;

public:
    void addSchool(const School& school) override {
        schools.push_back(school);
    }

    void removeSchool(const std::string& name, double latitude, double longitude) override {
        auto it = std::remove_if(schools.begin(), schools.end(), [&](const School& s) {
            return s.getName() == name && s.getLatitude() == latitude && s.getLongitude() == longitude;
            });
        if (it != schools.end()) {
            schools.erase(it, schools.end());
            // The school was found and removed
            cout << "School " << name << " at (" << latitude << ", " << longitude << ") was successfully removed.\n";
        }
        else {
            // The school was not found
            cout << "School " << name << " at (" << latitude << ", " << longitude << ") was not found.\n";
        }
    }

    std::vector<School> getAllSchools() const override {
        auto schoolsCopy = schools;
        std::sort(schoolsCopy.begin(), schoolsCopy.end(), [](const School& s1, const School& s2) {
            if (s1 - s2 < 0)
                return true;
            else
                return false;
            });

        return schoolsCopy;
    }



    std::vector<School> getSchoolsByPlannedVisitDate(const std::chrono::system_clock::time_point& date) const override {
        std::vector<School> filteredSchools;
        std::copy_if(schools.begin(), schools.end(), back_inserter(filteredSchools), [&](const School& s) {
            return s.getPlannedVisitDate() > date;
            });
        return filteredSchools;
    }
};

