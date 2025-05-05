#include "mainwindow.h"
#include "mainscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    button = new QPushButton("开始游戏", this);
    button->setGeometry(100, 100, 200, 50);
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    mainScene = new MainScene();
}

MainWindow::~MainWindow()
{
    delete mainScene;
}

void MainWindow::onButtonClicked()
{
    this->hide();
    mainScene->show();
}
