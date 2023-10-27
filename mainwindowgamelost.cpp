#include "mainwindowgamelost.h"
#include "ui_mainwindowgamelost.h"

MainWindowGameLost::MainWindowGameLost(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGameLost)
{
    ui->setupUi(this);
    QWidget::setStyleSheet("background-color: black;");
    QPixmap *png = new QPixmap("../GoaManjatFinal/textures/360_F_312548010_JsXZ9vxIXTbgZlDr1IwlMTogrN84BN1L.jpg");
    ui->label->setPixmap(*png);
    ui->label->setScaledContents(true);
}

MainWindowGameLost::~MainWindowGameLost()
{
    delete ui;
}
