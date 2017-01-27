#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextBrowser>

class MainWindow : public QMainWindow
{
    Q_OBJECT
        QWidget *centralWidget;
        QGridLayout *mainLayout;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createUI();

private:
    QComboBox *typeBox;
    QLabel *valueLabel;
    QPushButton *pushButton;
    QPushButton *popButton;
    QPushButton *refreshButton;
    QPushButton *clearButton;
    QLineEdit *pushValue;
    QLineEdit *popValue;
    QSpacerItem *spacer;
    QTextBrowser *text;

private slots:
   /* void slotDraw();
    void slotPush(float value);
    float slotPop();
    void slotClear();
    void initDS();*/
};

#endif // MAINWINDOW_H
