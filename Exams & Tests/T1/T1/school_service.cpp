#include "school_service.h"
#include "school.h"
#include "repo.h"

#include <algorithm>

SchoolService::SchoolService(SchoolRepo& repo) : repo(repo) {}

/*
 * Preconditions:
 *   - `name` is a valid non-empty string representing the name of the school
 *   - `lat` and `lon` are valid real numbers representing geographic coordinates
 *   - `date` is a string representing a valid date (format is not strictly enforced)
 *
 * Postconditions:
 *   - If no school with the same name and coordinates already exists, it is added to the repository and the function returns true
 *   - If such a school already exists (duplicate), the repository remains unchanged and the function returns false
 */
bool SchoolService::addSchool(const std::string& name, double lat, double lon, const std::string& date) {
    School s(name, lat, lon, date);
    return repo.addSchool(s);
}

/*
 * Preconditions:
 *   - None
 *
 * Postconditions:
 *   - Returns a vector containing all School objects currently stored in the repository
 */
std::vector<School> SchoolService::getAllSchools() const {
    return repo.getAll();
}

/*
 * Preconditions:
 *   - `lat` and `lon` are valid coordinates representing a location
 *   - `n` is a positive integer (default value is 3)
 *
 * Postconditions:
 *   - Returns a vector with the `n` closest School objects to the given location, sorted in ascending order of distance
 *   - If the repository contains fewer than `n` schools, all available schools are returned
 *   - If two schools have the same distance to the point, they are ordered lexicographically by name
 */

std::vector<School> SchoolService::getClosestSchools(double lat, double lon, int n) const {
    std::vector<School> all = repo.getAll();
    std::sort(all.begin(), all.end(), [](const School& a, const School& b) {
        return a.getName() < b.getName();
        


        });
    return all;
}
