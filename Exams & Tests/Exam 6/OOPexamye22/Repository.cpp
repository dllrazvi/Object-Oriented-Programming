#include "Repository.h"
#include <QFile>
#include <QTextStream>

std::vector<Event> Repository::readEvents() {
    std::vector<Event> events;
    QFile file("events.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return events;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 6) {
            events.push_back(Event(parts[0], parts[1], parts[2].toDouble(), parts[3].toDouble(), parts[4], parts[5].toBool()));
        }
    }
    file.close();
    return events;
}

std::vector<Person> Repository::readPersons() {
    std::vector<Person> persons;
    QFile file("persons.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return persons;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 4) {
            persons.push_back(Person(parts[0], parts[1].toDouble(), parts[2].toDouble(), parts[3].toBool()));
        }
    }
    file.close();
    return persons;
}

void Repository::writeEvents(const std::vector<Event>& events) {
    QFile file("events.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    for (const auto& event : events) {
        out << event.getName() << ","
            << event.getDescription() << ","
            << event.getLatitude() << ","
            << event.getLongitude() << ","
            << event.getDate() << ","
            << event.getOrganizer() << "\n";
    }
    file.close();
}

void Repository::writePersons(const std::vector<Person>& persons) {
    QFile file("persons.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    for (const auto& person : persons) {
        out << person.getName() << ","
            << person.getLatitude() << ","
            << person.getLongitude() << ","
            << person.isOrganizer() << "\n";
    }
    file.close();
}
