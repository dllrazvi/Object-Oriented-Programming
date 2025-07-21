#include <QApplication>
#include "OOPexamye22.h"
#include "Service.h"
#include "Repository.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Repository repo;
    Service service(&repo);
    OOPexamye22 w(&service);
    w.show();

    return a.exec();
}
