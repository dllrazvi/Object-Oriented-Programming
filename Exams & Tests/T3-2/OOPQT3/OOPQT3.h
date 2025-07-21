#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPQT3.h"
#include <QFile>
#include <QTextStream>
#include <DocumentRepository.h>

class OOPQT3 : public QMainWindow
{
    Q_OBJECT

public:
    OOPQT3(QWidget *parent = nullptr);
    ~OOPQT3();

private:
    void filterDocuments();
    void showBestMatch();
    Ui::OOPQT3Class ui;
    DocumentRepository repo;
    void loadDocumentsToList();
};
