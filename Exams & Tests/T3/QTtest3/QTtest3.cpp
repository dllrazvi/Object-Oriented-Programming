#include "QTtest3.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>

QTtest3::QTtest3(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Initialize and connect widgets
    intensityInput = findChild<QLineEdit*>("intensityInput");
    filterButton = findChild<QPushButton*>("filterButton");
    sessionList = findChild<QListWidget*>("sessionList");
    typeInput = findChild<QLineEdit*>("typeInput");
    startTimeInput = findChild<QLineEdit*>("startTimeInput");
    showIntervalsButton = findChild<QPushButton*>("showIntervalsButton");
    intervalList = findChild<QListWidget*>("intervalList");
    totalHoursLabel = findChild<QLabel*>("totalHoursLabel");

    connect(filterButton, &QPushButton::clicked, this, &QTtest3::filterSessions);
    connect(showIntervalsButton, &QPushButton::clicked, this, &QTtest3::showIntervals);

    loadSessionList();
    updateSessionList();
}

QTtest3::~QTtest3() {}

void QTtest3::loadSessionList()
{
    QFile file("sessions.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';');
        if (parts.size() == 5) {
            QString start = parts[0];
            QString end = parts[1];
            QString type = parts[2];
            QString intensity = parts[3];
            QString description = parts[4];
            sessions.push_back(Session(start, end, type, intensity, description));
        }
    }

    file.close();
}

void QTtest3::updateSessionList()
{
    std::sort(sessions.begin(), sessions.end(), [](const Session& a, const Session& b) {
        return a.getStart().toInt() < b.getStart().toInt();
        });

    sessionList->clear();
    for (const Session& session : sessions) {
        QListWidgetItem* item = new QListWidgetItem(session.getStart() + "-" + session.getEnd() + ": " + session.getType() + " (" + session.getIntensity() + ") - " + session.getDescription());
        sessionList->addItem(item);
    }
}

void QTtest3::filterSessions()
{
    QString intensity = intensityInput->text();
    sessionList->clear();

    for (const Session& session : sessions) {
        if (session.getIntensity().toInt() > intensity.toInt()) {
            QListWidgetItem* item = new QListWidgetItem(session.getStart() + "-" + session.getEnd() + ": " + session.getType() + " (" + session.getIntensity() + ") - " + session.getDescription());
            sessionList->addItem(item);
        }
    }
}

void QTtest3::showIntervals()
{
    QString type = typeInput->text();
    int startTime = startTimeInput->text().toInt();
    int totalHours = 0;
    intervalList->clear();

    for (const Session& session : sessions) {
        if (session.getType().compare(type, Qt::CaseInsensitive) == 0 && session.getStart().toInt() >= startTime) {
            QListWidgetItem* item = new QListWidgetItem(session.getStart() + "-" + session.getEnd() + ": " + session.getType() + " (" + session.getIntensity() + ") - " + session.getDescription());
            intervalList->addItem(item);
            int start = session.getStart().toInt();
            int end = session.getEnd().toInt();
            totalHours += end - start;
        }
    }

    if (totalHours > 0) {
        totalHoursLabel->setText("Total Hours: " + QString::number(totalHours));
    }
    else {
        totalHoursLabel->setText("No such intervals found.");
    }
}
