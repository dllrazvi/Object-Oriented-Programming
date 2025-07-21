#include "Service.h"
#include <chrono>
#include <iomanip>
#include <sstream>

SchoolService::SchoolService(SchoolRepository& repository)
    : repository_{ repository }
{}

void SchoolService::addSchool(const std::string& name, double latitude, double longitude, const std::string& plannedVisitDate) {
    std::stringstream ss(plannedVisitDate);
    std::tm visitDate = {};
    ss >> std::get_time(&visitDate, "%d.%m.%Y");
    if (ss.fail()) {
        throw std::invalid_argument("Invalid date format. Use dd.mm.yyyy.");
    }
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&visitDate));
    auto school = School{ name, latitude, longitude, tp };
    repository_.addSchool(school);
}

void SchoolService::removeSchool(const std::string& name, double latitude, double longitude) {
    repository_.removeSchool(name, latitude, longitude);
}

std::vector<School> SchoolService::getAllSchools() const {
    return repository_.getAllSchools();
}

std::vector<School> SchoolService::getSchoolsByPlannedVisitDate(const std::string& date) const {
    std::stringstream ss(date);
    std::tm visitDate = {};
    ss >> std::get_time(&visitDate, "%d.%m.%Y");
    if (ss.fail()) {
        throw std::invalid_argument("Invalid date format. Use dd.mm.yyyy.");
    }
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&visitDate));
    return repository_.getSchoolsByPlannedVisitDate(tp);
}

std::vector<School> SchoolService::getSchoolsByPlannedVisitDateAfter(const std::string& date) const {
    std::stringstream ss(date);
    std::tm visitDate = {};
    ss >> std::get_time(&visitDate, "%d.%m.%Y");
    if (ss.fail()) {
        throw std::invalid_argument("Invalid date format. Use dd.mm.yyyy.");
    }
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&visitDate));
    return repository_.getSchoolsByPlannedVisitDateAfter(tp);
}

void SchoolService::markSchoolAsVisited(const std::string& name, double latitude, double longitude) {
    repository_.markSchoolAsVisited(name, latitude, longitude);
}
