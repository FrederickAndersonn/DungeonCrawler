#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DungeonCrawler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setStyleSheet("background-color: black;");
    QPixmap *png = new QPixmap("../GoaManjatFinal/textures/startscreen.png");
    ui->startscreen->setPixmap(*png);
    ui->startscreen->setScaledContents(true);
    QPixmap buttonTexture("../GoaManjatFinal/textures/new_game_button.png");
    QSize buttonSize(110,100);
    QIcon buttonImage(buttonTexture);
    ui->pushButton->setIcon(buttonImage);
    ui->pushButton->setIconSize(buttonSize);
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    delete png;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setToMain(MainWindowGame* mg){
    toMain = mg;
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::hide();
    toMain->show();
}


