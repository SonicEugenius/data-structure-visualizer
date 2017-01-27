#include "mainwindow.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>

void MainWindow::createUI() {
    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    mainLayout = new QGridLayout;
    centralWidget->setLayout(mainLayout);

    QVBoxLayout *toolsLayout = new QVBoxLayout;
    typeBox = new QComboBox;
    typeBox->addItems({"Stack", "Queue", "Binary tree", "Red-black tree"});
    typeBox->setFixedWidth(200);
    toolsLayout->addWidget(typeBox);

    QHBoxLayout *pushLayout = new QHBoxLayout;
    pushButton = new QPushButton("Push");
    pushValue = new QLineEdit;
    pushValue->setPlaceholderText("Value");
    pushButton->setFixedSize(90, 30);
    pushValue->setFixedSize(90, 30);
    pushLayout->addWidget(pushValue);
    pushLayout->addWidget(pushButton);

    toolsLayout->addLayout(pushLayout);
    popButton = new QPushButton("Pop");
    refreshButton = new QPushButton("Refresh");
    clearButton = new QPushButton("Clear");
    popButton->setFixedSize(100, 30);
    refreshButton->setFixedSize(100, 30);
    clearButton->setFixedSize(100, 30);

    toolsLayout->addWidget(popButton);
    toolsLayout->addWidget(refreshButton);
    toolsLayout->addWidget(clearButton);

    spacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    toolsLayout->addSpacerItem(spacer);
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
    toolsLayout->setAlignment(popButton, Qt::AlignCenter);
    toolsLayout->setAlignment(refreshButton, Qt::AlignCenter);
    toolsLayout->setAlignment(clearButton, Qt::AlignCenter);
    QHBoxLayout *wrapper = new QHBoxLayout;
    wrapper->addWidget(text);
    wrapper->addLayout(toolsLayout);

    mainLayout->addLayout(wrapper, 0, 0);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

MainWindow::~MainWindow()
{

}
