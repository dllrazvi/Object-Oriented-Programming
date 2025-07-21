/*#ifndef VOLUNTEERDIALOG_H
#define VOLUNTEERDIALOG_H

#include <QDialog>
#include "ui_OOPexamye2.h"  // Ensure this matches the generated header file name

class VolunteerDialog : public QDialog {
    Q_OBJECT

public:
    explicit VolunteerDialog(QWidget* parent = nullptr);
    ~VolunteerDialog();

private:
    Ui::OOPexamye2* ui;  // This will use the class name based on your .ui file name

    void setupUi();
};

#endif // VOLUNTEERDIALOG_H
