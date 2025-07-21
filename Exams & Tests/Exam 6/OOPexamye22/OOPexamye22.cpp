#include "OOPexamye22.h"
#include "ui_OOPexamye22.h"
#include "PersonWindow.h"
#include "PopularEventsWindow.h"
#include "Repository.h"
#include "Service.h"

OOPexamye22::OOPexamye22(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::OOPexamye22)
{
    ui->setupUi(this);

    Repository repo;
    Service service(&repo);

    allEvents = service.getEvents();
    allPersons = service.getPersons();

    for (const auto& person : allPersons) {
        PersonWindow* personWindow = new PersonWindow(person, allEvents);
        personWindow->setWindowTitle(person.getName());
        personWindow->show();
    }
}

OOPexamye22::~OOPexamye22()
{
    delete ui;
}

void OOPexamye22::on_showPopularEventsButton_clicked()
{
    PopularEventsWindow* popularEventsWindow = new PopularEventsWindow(allEvents);
    popularEventsWindow->show();
}
