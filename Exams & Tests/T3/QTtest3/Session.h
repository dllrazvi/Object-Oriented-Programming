#pragma once
#include <QString>

class Session {
public:
    Session(const QString& start, const QString& end, const QString& type, const QString& intensity, const QString& description)
        : start(start), end(end), type(type), intensity(intensity), description(description) {}

    QString getStart() const { return start; }
    QString getEnd() const { return end; }
    QString getType() const { return type; }
    QString getIntensity() const { return intensity; }
    QString getDescription() const { return description; }

private:
    QString start;
    QString end;
    QString type;
    QString intensity;
    QString description;
};
