#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class OOPexamye2;  // Forward declaration for the UI class generated from OOPexamye2.ui
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::OOPexamye2* ui;  // Pointer to the UI class for accessing widgets
};

#endif // MAINWINDOW_H
