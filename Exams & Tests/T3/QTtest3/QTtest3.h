#pragma once

#include <QtWidgets/QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include "ui_QTtest3.h"
#include "Session.h"

class QTtest3 : public QMainWindow
{
    Q_OBJECT

public:
    QTtest3(QWidget* parent = nullptr);
    ~QTtest3();

private slots:
    void filterSessions();
    void showIntervals();

private:
    Ui::QTtest3Class ui;
    void loadSessionList();
    void updateSessionList();
    std::vector<Session> sessions;

    QLineEdit* intensityInput;
    QPushButton* filterButton;
    QListWidget* sessionList;
    QLineEdit* typeInput;
    QLineEdit* startTimeInput;
    QPushButton* showIntervalsButton;
    QListWidget* intervalList;
    QLabel* totalHoursLabel;
};
