#include "mainwindow.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QTextCursor>
#include <QString>

void MainWindow::createUI() {
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    mainLayout = new QGridLayout;
    centralWidget->setLayout(mainLayout);

    QVBoxLayout *toolsLayout = new QVBoxLayout;
    typeBox = new QComboBox;
    typeBox->addItems({"Stack", "Queue"/*, "Binary search tree", "Red-black tree"*/});
    typeBox->setFixedWidth(200);
    toolsLayout->addWidget(typeBox);

    selectButton = new QPushButton("Select");
    selectButton->setFixedSize(90, 30);
    toolsLayout->addWidget(selectButton);
    toolsLayout->setAlignment(typeBox, Qt::AlignHCenter);
    toolsLayout->setAlignment(typeBox, Qt::AlignTop);

    spacer_1 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    toolsLayout->addSpacerItem(spacer_1);

    QHBoxLayout *pushLayout = new QHBoxLayout;
    pushButton = new QPushButton("Push");
    enqueueButton = new QPushButton("Enqueue");
    pushValue = new QLineEdit;
    pushValue->setPlaceholderText("Value");
    pushButton->setFixedSize(90, 30);
    pushValue->setFixedSize(90, 30);
    pushLayout->addWidget(pushValue);
    pushLayout->addWidget(pushButton);
    pushLayout->addWidget(enqueueButton);

    toolsLayout->addLayout(pushLayout);
    popButton = new QPushButton("Pop");
    dequeueButton = new QPushButton("Dequeue");
    clearButton = new QPushButton("Clear");
    popButton->setFixedSize(100, 30);
    enqueueButton->setFixedSize(100, 30);
    dequeueButton->setFixedSize(100, 30);
    clearButton->setFixedSize(100, 30);

    toolsLayout->addWidget(popButton);
    toolsLayout->addWidget(dequeueButton);
    toolsLayout->addWidget(clearButton);

    spacer_2 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    toolsLayout->addSpacerItem(spacer_2);
    QHBoxLayout *popLayout = new QHBoxLayout;
    valueLabel = new QLabel("Value: ");
    popValue = new QLineEdit;
    popValue->setReadOnly(true);
    valueLabel->setFixedSize(90, 30);
    popValue->setFixedSize(90, 30);
    popLayout->addWidget(valueLabel);
    popLayout->addWidget(popValue);
    toolsLayout->addLayout(popLayout);

    text = new QTextBrowser;
    text->setReadOnly(true);
    text->setFontPointSize(16);

    toolsLayout->setContentsMargins(15, 20, 15, 20);
    toolsLayout->setAlignment(selectButton, Qt::AlignCenter);
    toolsLayout->setAlignment(popButton, Qt::AlignCenter);
    toolsLayout->setAlignment(dequeueButton, Qt::AlignCenter);
    toolsLayout->setAlignment(clearButton, Qt::AlignCenter);
    QHBoxLayout *wrapper = new QHBoxLayout;
    wrapper->addWidget(text);
    wrapper->addLayout(toolsLayout);

    pushButton->setVisible(false);
    popButton->setVisible(false);
    enqueueButton->setVisible(false);
    dequeueButton->setVisible(false);
    valueLabel->setVisible(false);
    popValue->setVisible(false);
    pushValue->setVisible(false);
    clearButton->setVisible(false);

    mainLayout->addLayout(wrapper, 0, 0);

    connect(selectButton, SIGNAL(clicked()), this, SLOT(slotInitDS()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(slotClear()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

void MainWindow::slotInitDS() {
    int type = typeBox->currentIndex();
    switch (type) {
    case 0: stack = new QStack<float>;
        pushButton->setVisible(true);
        popButton->setVisible(true);
        popBuff = "";
        break;
    case 1: queue = new QQueue<float>;
        enqueueButton->setVisible(true);
        dequeueButton->setVisible(true);
        text->append("\n");
        dequeueBuff = "";
        deqTextBuff = "";
        break;
   // case "Binary tree":
   // case "Red-black tree":
    }
    typeBox->setEnabled(false);
    selectButton->setVisible(false);
    clearButton->setVisible(true);
    pushValue->setVisible(true);
    pushValue->setFocus();
    valueLabel->setVisible(true);
    popValue->setVisible(true);

    popButton->setEnabled(false);
    dequeueButton->setEnabled(false);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(slotPush()));
    connect(popButton, SIGNAL(clicked()), this, SLOT(slotPop()));
    connect(enqueueButton, SIGNAL(clicked()), this, SLOT(slotEnqueue()));
    connect(dequeueButton, SIGNAL(clicked()), this, SLOT(slotDequeue()));
}

void MainWindow::slotPush() {
    float value = pushValue->text().toFloat();
    stack->push(value);
    if (!stack->isEmpty()) popButton->setEnabled(true);
    popBuff.insert(0, QString().number(value) + '\n');
    pushValue->clear();
    pushValue->setFocus();
    text->clear();
    text->setText("\n");
    text->setAlignment(Qt::AlignCenter);
    text->append(popBuff);
    text->setAlignment(Qt::AlignCenter);
}

void MainWindow::slotPop() {
    float value = stack->pop();
     popValue->setText(QString().number(value));
     if (stack->isEmpty()) popButton->setEnabled(false);
     int r = QString().number(value).length();
     r++;
     popBuff.remove(0, r);
     text->clear();
     text->setText("\n");
     text->setTextColor("red");
     text->setAlignment(Qt::AlignCenter);
     text->append(QString().number(value));
     text->setAlignment(Qt::AlignCenter);
     text->setTextColor("black");
     text->append(popBuff);
     text->setAlignment(Qt::AlignCenter);
}

void MainWindow::slotEnqueue() {
    float value = pushValue->text().toFloat();
    queue->enqueue(value);
    if (!queue->isEmpty()) dequeueButton->setEnabled(true);
    pushValue->clear();
    pushValue->setFocus();
    text->append(QString().number(value));
    text->setAlignment(Qt::AlignCenter);
    dequeueBuff.append(QString().number(value) + '\n');
}

void MainWindow::slotDequeue() {
    float value = queue->dequeue();
    popValue->setText(QString().number(value));
    if (queue->isEmpty()) dequeueButton->setEnabled(false);
    int r = QString().number(value).length();
    r++;
    dequeueBuff.remove(0, r);
    deqTextBuff.append("\n");
    text->clear();
    text->setText(deqTextBuff);
    text->setTextColor("red");
    text->setAlignment(Qt::AlignCenter);
    text->append(QString().number(value));
    text->setAlignment(Qt::AlignCenter);
    text->setTextColor("black");
    text->append(dequeueBuff);
    text->setAlignment(Qt::AlignCenter);

}

void MainWindow::slotClear() {
    createUI();
}

MainWindow::~MainWindow()
{

}
