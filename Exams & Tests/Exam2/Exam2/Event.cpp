#include "Event.h"
#include <sstream>

std::string Event::toString() const {
    std::ostringstream os;
    os << name << " (" << date << ") at [" << latitude << "," << longitude << "]";
    os << " | Organiser: " << organiser;
    os << " | " << attendees.size() << " going";
    return os.str();
}

bool Event::isSame(const Event& other) const {
    return name == other.name &&
        latitude == other.latitude &&
        longitude == other.longitude;
}
