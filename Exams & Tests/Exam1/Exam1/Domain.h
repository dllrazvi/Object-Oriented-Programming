#pragma once
#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <string>
#include <chrono>

class School {
private:
    std::string name;
    double latitude;
    double longitude;
    std::chrono::system_clock::time_point plannedVisitDate;
    bool visited;

public:
    School(const std::string& name, double latitude, double longitude,
        std::chrono::system_clock::time_point plannedVisitDate, bool visited);
    std::string getName() const;
    double getLatitude() const;
    double getLongitude() const;
    std::chrono::system_clock::time_point getPlannedVisitDate() const;
    bool isVisited() const;
    void setVisited(bool visited);
};

#endif // DOMAIN_HPP
