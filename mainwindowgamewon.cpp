#include "mainwindowgamewon.h"
#include "ui_mainwindowgamewon.h"

MainWindowGameWon::MainWindowGameWon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGameWon)
{
    ui->setupUi(this);
    QWidget::setStyleSheet("background-color: black;");
    QPixmap *png = new QPixmap("../GoaManjatFinal/textures/pixel-art-8-bit-you-win-text-with-one-big-winner-golden-cup-on-black-background-isolated-vector-illustration-2bw100t.jpg");
    ui->label->setPixmap(*png);
    ui->label->setScaledContents(true);
}

MainWindowGameWon::~MainWindowGameWon()
{
    delete ui;
}
