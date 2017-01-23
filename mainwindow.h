#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton pushButton;
    QPushButton popButton;
    QPushButton refreshButton;
    QPushButton clearButton;
    QLineEdit pushValue;
    QLineEdit popValue;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
