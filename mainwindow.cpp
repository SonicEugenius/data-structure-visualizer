#include "mainwindow.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QString>

void MainWindow::createUI() {
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    mainLayout = new QGridLayout;
    centralWidget->setLayout(mainLayout);

    QVBoxLayout *toolsLayout = new QVBoxLayout;
    typeBox = new QComboBox;
    typeBox->addItems({"Stack", "Queue"/*, "Binary tree", "Red-black tree"*/});
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
    refreshButton = new QPushButton("Refresh");
    clearButton = new QPushButton("Clear");
    popButton->setFixedSize(100, 30);
    enqueueButton->setFixedSize(100, 30);
    dequeueButton->setFixedSize(100, 30);
    refreshButton->setFixedSize(100, 30);
    clearButton->setFixedSize(100, 30);

    toolsLayout->addWidget(popButton);
    toolsLayout->addWidget(dequeueButton);
    toolsLayout->addWidget(refreshButton);
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

    toolsLayout->setContentsMargins(15, 20, 15, 20);
    toolsLayout->setAlignment(selectButton, Qt::AlignCenter);
    toolsLayout->setAlignment(popButton, Qt::AlignCenter);
    toolsLayout->setAlignment(dequeueButton, Qt::AlignCenter);
    toolsLayout->setAlignment(refreshButton, Qt::AlignCenter);
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
    refreshButton->setVisible(false);
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
        //text->setText("Stack");
        pushButton->setVisible(true);
        popButton->setVisible(true);
        break;
    case 1: queue = new QQueue<float>;
        //text->setText("Queue");
        enqueueButton->setVisible(true);
        dequeueButton->setVisible(true);
        break;
   // case "Binary tree":
   // case "Red-black tree":
    }
    typeBox->setEnabled(false);
    selectButton->setVisible(false);
    refreshButton->setVisible(true);
    clearButton->setVisible(true);
    pushValue->setVisible(true);
    valueLabel->setVisible(true);
    popValue->setVisible(true);
}

void MainWindow::slotClear() {
    createUI();
}

MainWindow::~MainWindow()
{

}
