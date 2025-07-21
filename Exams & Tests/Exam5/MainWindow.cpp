#include "MainWindow.h"
#include "ui_OOPexamye2.h"  // Include the generated header file from the OOPexamye2.ui file

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::OOPexamye2) {

    ui->setupUi(this);  
}

MainWindow::~MainWindow() {
    delete ui;
}
