#include "Exam.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include "repository.h"
#include <QSortFilterProxyModel>
#include <vector>
#include <QMessageBox>
#include <QAbstractTableModel>
#include <QtWidgets/QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Repository repo{};
    Service service{ repo };

    std::vector<Person> persons = service.getAllPersons();
    for (auto& p : persons)
    {
        Exam* exam = new Exam{ service,p };
        exam->setWindowTitle(QString::fromStdString(p.getName()));
        exam->show();
    }

    return a.exec();
}
