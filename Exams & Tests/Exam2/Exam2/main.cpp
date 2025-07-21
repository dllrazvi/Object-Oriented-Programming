#include "Exam2.h"
#include "PersonWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    FileRepo repo("people.txt", "events.txt");
    Service srv(repo);

    std::vector<QWidget*> windows;

    for (const auto& p : srv.getPersons()) {
        auto* w = new PersonWindow(p, srv);
        w->show();
        windows.push_back(w);
    }

    return a.exec();
}
