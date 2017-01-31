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
#include <QStack>
#include <QQueue>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT
        QWidget *centralWidget;
        QGridLayout *mainLayout;
        QString popBuff;
        QString dequeueBuff;
        QString deqTextBuff;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createUI();

private:
    QComboBox *typeBox;
    QLabel *valueLabel;
    QPushButton *selectButton;
    QPushButton *pushButton;
    QPushButton *popButton;
    QPushButton *enqueueButton;
    QPushButton *dequeueButton;
    QPushButton *drawButton;
    QPushButton *clearButton;
    QLineEdit *pushValue;
    QLineEdit *popValue;
    QSpacerItem *spacer_1, *spacer_2;
    QTextBrowser *text;
    QStack<float> *stack;
    QQueue<float> *queue;

private slots:
    //void slotDraw();
    void slotPush();
    void slotPop();
    void slotEnqueue();
    void slotDequeue();
    void slotClear();
    void slotInitDS();
};

#endif // MAINWINDOW_H
