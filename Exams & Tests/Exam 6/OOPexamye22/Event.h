#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QList>
#include <QVector>

class Event {
public:
    Event(const QString& name, const QString& description, double latitude, double longitude, const QString& date, bool organizer)
        : name(name), description(description), latitude(latitude), longitude(longitude), date(date), organizer(organizer) {}

    QString getName() const { return name; }
    QString getDescription() const { return description; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
    QString getDate() const { return date; }
    bool getOrganizer() const { return organizer; }

private:
    QString name;
    QString description;
    double latitude;
    double longitude;
    QString date;
    bool organizer;
    QVector<QString> attendees;
};

#endif // EVENT_H
