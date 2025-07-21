/*#include "VolunteerDialog.h"
#include <QMessageBox>
#include <QPushButton>
#include "ui_OOPexamye2.h"


VolunteerDialog::VolunteerDialog(QWidget* parent) : QDialog(parent), ui(new Ui::OOPexamye2()) {
    ui->setupUi(this);  // Set up the UI

    // Connect the signals and slots for the buttons
    connect(ui->saveButton, &QPushButton::clicked, this, &VolunteerDialog::onSaveClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &VolunteerDialog::reject);
}

VolunteerDialog::~VolunteerDialog() {
    delete ui;
}

void VolunteerDialog::onSaveClicked() {
    // Example validation before saving
    if (ui->nameEdit->text().isEmpty() || ui->emailEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Name and email cannot be empty.");
        return;
    }

    // Proceed to save the data or emit a signal
    QDialog::accept();
}
*/