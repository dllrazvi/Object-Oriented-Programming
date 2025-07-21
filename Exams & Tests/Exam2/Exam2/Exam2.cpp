#include "Exam2.h"
#include "ui_Exam2.h"
#include "PersonWindow.h"

Exam2::Exam2(Service& srv, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Exam2), service(srv)
{
    ui->setupUi(this);
    loadPersonList();
    connect(ui->btnOpenPerson, &QPushButton::clicked, this, &Exam2::openPersonWindow);
}

Exam2::~Exam2() {
    delete ui;
}

void Exam2::loadPersonList() {
    ui->listPersons->clear();
    for (const auto& p : service.getPersons()) {
        ui->listPersons->addItem(QString::fromStdString(p.toString()));
    }
}

void Exam2::openPersonWindow() {
    auto item = ui->listPersons->currentItem();
    if (!item) return;

    std::string name = item->text().split(" ")[0].toStdString();
    for (const auto& p : service.getPersons())
        if (p.getName() == name) {
            auto* win = new PersonWindow(p, service);
            win->show();
        }
}
