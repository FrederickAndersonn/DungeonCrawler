#include "mainwindowgame.h"
#include "ui_mainwindowgame.h"
#include "DungeonCrawler.h"
#include "Pit.h"
#include "Level.h"
#include "Ramp.h"
#include "Wall.h"
#include "json.hpp"
#include "mainwindow.h"
#include "dungeoncrawlersaver.h"
using namespace std;
MainWindowGame::MainWindowGame(GraphicalUI *gui, QWidget *parent) : gui(gui),
    QMainWindow(parent),
    ui(new Ui::MainWindowGame)
{
    ui->setupUi(this);
    QPixmap *png = new QPixmap("../GoaManjatFinal/textures/bloody_frame.png");
    ui->label->setPixmap(*png);
    ui->label->setScaledContents(true);
    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);
    setButton();

}

MainWindowGame::MainWindowGame(GraphicalUI *gui, DungeonCrawler * dc, QWidget *parent): gui(gui), dc(dc), QMainWindow(parent), ui(new Ui::MainWindowGame)
{
    ui->setupUi(this);
    QPixmap *png = new QPixmap("../GoaManjatFinal/textures/bloody_frame.png");
    ui->label->setPixmap(*png);
    ui->label->setScaledContents(true);
    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);
    setButton();

}

MainWindowGame::~MainWindowGame()
{
    delete ui;
}

void MainWindowGame::printLevel(GraphicalUI* gui){
    setProgressBar();
       for (int i = 0; i < gui->getLevel()->getMaxRow()+1; i++) {
           textureList.emplaceBack();
           for (int j = 0; j < gui->getLevel()->getMaxColumn()+1;j++) {
               delete ui->gridLayout->itemAtPosition(i,j);
               ui->gridLayout->removeItem(ui->gridLayout->itemAtPosition(i,j));

               Tile* thisTile = gui->getLevel()->getTile(i,j);
               if(typeid(*thisTile) == typeid(Door)){
                   Door* door = dynamic_cast<Door*>(thisTile);
                   textureList[i].push_back(door->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Floor)){
                   Floor* floor = dynamic_cast<Floor*>(thisTile);
                   textureList[i].push_back(floor->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Switch)){
                   Switch* switchh = dynamic_cast<Switch*>(thisTile);
                   textureList[i].push_back(switchh->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Pit)){
                   Pit* pit = dynamic_cast<Pit*>(thisTile);
                  textureList[i].push_back(pit->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Ramp)){
                   Ramp* ramp= dynamic_cast<Ramp*>(thisTile);
                   textureList[i].push_back(ramp->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Portal)){
                   Portal* portal = dynamic_cast<Portal*>(thisTile);
                   if(i%2==0)
                       textureList[i].push_back(portal->getTextureGUI());
                   else
                       textureList[i].push_back(portal->getTextureGUI2());
               }
               if(typeid(*thisTile) == typeid(Wall)){
                   Wall* wall = dynamic_cast<Wall*>(thisTile);
                   textureList[i].push_back(wall->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Levelchanger)){
                   Levelchanger* lc = dynamic_cast<Levelchanger*>(thisTile);
                   textureList[i].push_back(lc->getTextureGUI());
               }
               if(typeid(*thisTile) == typeid(Lootchest)){
                   Lootchest* loot = dynamic_cast<Lootchest*>(thisTile);
                   textureList[i].push_back(loot->getTextureGUI());
               }

               QPixmap*qpix = textureList[i][j];
               QLabel* obj = new QLabel();//delete???
               obj->setPixmap(*qpix);
               obj->setScaledContents(true);
               if(thisTile->hasCharacter()){
                   Character* thisChar = thisTile->getCharacter();
                   QLabel* charLabel = new QLabel();
                   charLabel->setPixmap(*thisChar->getTextureC());
                   charLabel->resize(obj->size());

                   if(typeid(*thisTile) != typeid(Pit)){
                       ui->gridLayout->removeWidget(obj);
                       ui->gridLayout->removeWidget(charLabel);
                       ui->gridLayout->addWidget(obj,i,j);
                       charLabel->setParent(this);
                       ui->gridLayout->addWidget(charLabel,i,j);
                     }
                   else{
                       ui->gridLayout->removeWidget(obj);
                       ui->gridLayout->removeWidget(charLabel);
                        charLabel->setParent(obj);
                        ui->gridLayout->addWidget(charLabel,i,j);
                        ui->gridLayout->addWidget(obj,i,j);

                      }
                    resizeCharacter(gui,charLabel,charLabel);
               }
               else{
                   ui->gridLayout->removeWidget(obj);
                   ui->gridLayout->addWidget(obj, i , j);
               }
               if(typeid(*thisTile) == typeid(Door)){
                   Door* door = dynamic_cast<Door*>(thisTile);
                   setTextureAt(i,j,door->getTextureGUI());
               }

           }
       }

   }
void MainWindowGame::setButton(){
    ui->pushButton->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_up_left.png"));
    ui->pushButton->setIconSize(ui->pushButton->size());
    ui->pushButton_2->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_up.png"));
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());
    ui->pushButton_3->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_up_right.png"));
    ui->pushButton_3->setIconSize(ui->pushButton_3->size());
    ui->pushButton_4->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_left.png"));
    ui->pushButton_4->setIconSize(ui->pushButton_4->size());
    ui->pushButton_5->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_skip.png"));
    ui->pushButton_5->setIconSize(ui->pushButton_5->size());
    ui->pushButton_6->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_right.png"));
    ui->pushButton_6->setIconSize(ui->pushButton_6->size());
    ui->pushButton_7->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_down_left.png"));
    ui->pushButton_7->setIconSize(ui->pushButton_7->size());
    ui->pushButton_8->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_down.png"));
    ui->pushButton_8->setIconSize(ui->pushButton_8->size());
    ui->pushButton_9->setIcon(QPixmap("../GoaManjatFinal/textures/arrows/arrow_down_right.png"));
    ui->pushButton_9->setIconSize(ui->pushButton_9->size());
}

int MainWindowGame::getLastInput() const
{
    return lastInput;
}

void MainWindowGame::nextMove(int i){
    if(lastInput ==11){
        std::ifstream myfile(
              "/Users/frederickanderson/GoaManjatFinal/savefile.json");
          nlohmann::json dungeoncrawlerJSON;
          myfile >> dungeoncrawlerJSON;
          myfile.close();
        DungeonCrawler* dg =
              DungeonCrawlerSerializer::deserialize(dungeoncrawlerJSON, gui);
        MainWindow* w = new MainWindow;
        DoubleLinkedList<Levelchanger*> dll;
        MainWindowGameWon* mwgw = new MainWindowGameWon;
        MainWindowGameLost* mwgl = new MainWindowGameLost;
        MainWindowGame mg(gui, dg);
        gui->setMg(&mg);
        dg->setMwg(this);
        dg->setMwgw(mwgw);
        dg->setMwgl(mwgl);
        setDc(dg);
        gui->setDungeonCrawler(dg);
        dg->getCurrentAbstractUi()->draw(dg->getCurrentLvl());
        dg->turn(i);
        clear();
        textureList.clear();
        printLevel(gui);
    }
    else{
    gui->getDungeonCrawler()->turn(i);
    clear();
    printLevel(gui);
    }
}

void MainWindowGame::resizeCharacter(GraphicalUI* gui, QLabel* obj, QLabel* character){
    int totalArea = 609*539;
    int levelRow = gui->getLevel()->getMaxRow();
    int levelCol = gui->getLevel()->getMaxColumn();
    int oneBox = totalArea/(levelRow*levelCol);
    int height = obj->height()/levelRow;
    int width = obj->width()/levelCol;
    character->resize(oneBox/height, oneBox/width);
    character->setScaledContents(true);
}

void MainWindowGame::clear()
{
        QLayoutItem* li;
        while(ui->gridLayout->count() != 0){
            li = ui->gridLayout->takeAt(0);
         if(li->widget() != 0){
            delete li->widget();
         }
    }
}

void MainWindowGame::setTextureAt(int i, int j, QPixmap *val)
{
    textureList[i][j] = val;
}



void MainWindowGame::on_pushButton_clicked()
{
    lastInput=7;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_2_clicked()
{
    lastInput = 8;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_3_clicked()
{
    lastInput = 9;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_4_clicked()
{
    lastInput = 4;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_5_clicked()
{
    lastInput = 5;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_6_clicked()
{
    lastInput = 6;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_7_clicked()
{
    lastInput = 1;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_8_clicked()
{
    lastInput = 2;
    nextMove(lastInput);
}



void MainWindowGame::on_pushButton_9_clicked()
{
    lastInput = 3;
    nextMove(lastInput);
}

void MainWindowGame::clean() {

}

void MainWindowGame::setProgressBar()
{
    QString npc = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
    QString player= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 1 #0F0 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
    ui->progressBar->setStyleSheet(player);
    ui->progressBar->setRange(0,dc->getCurrentChar()->getMaxHP() );
    ui->progressBar->setValue(dc->getCurrentChar()->getHitpoints());
    ui->progressBar->setFormat("Health: "+ QString::number(dc->getCurrentChar()->getHitpoints())
                               +" Strength: "+QString::number(dc->getCurrentChar()->getStrength()));
    ui->progressBar_2->hide();
    ui->progressBar_3->hide();
    ui->progressBar_4->hide();
    ui->progressBar_2->setStyleSheet(npc);
    ui->progressBar_3->setStyleSheet(npc);
    ui->progressBar_4->setStyleSheet(npc);
    QFont font = ui->progressBar_2->font();
    font.setPointSize(10);
    ui->progressBar->setFont(font);
    ui->progressBar_2->setFont(font);
    ui->progressBar_3->setFont(font);
    ui->progressBar_4->setFont(font);
      if(dc->getCurrentLvl()->listOfCharacter.size()==1){
        ui->progressBar_2->show();
        ui->progressBar_2->setRange(0, dc->getCurrentLvl()->listOfCharacter.at(0)->getMaxHP());
        ui->progressBar_2->setValue(dc->getCurrentLvl()->listOfCharacter.at(0)->getHitpoints());
        ui->progressBar_2->setFormat("Health: "+ QString::number(dc->getCurrentLvl()->listOfCharacter.at(0)->getHitpoints())
                                     +" Strength: "+QString::number(dc->getCurrentLvl()->listOfCharacter.at(0)->getStrength()));
    }
      if(dc->getCurrentLvl()->listOfCharacter.size()==2){
         ui->progressBar_2->show();
         ui->progressBar_3->show();
         ui->progressBar_2->setRange(0, dc->getCurrentLvl()->listOfCharacter.at(0)->getMaxHP());
         ui->progressBar_2->setValue(dc->getCurrentLvl()->listOfCharacter.at(0)->getHitpoints());
         ui->progressBar_2->setFormat("Health: "+ QString::number(dc->getCurrentLvl()->listOfCharacter.at(0)->getHitpoints())
                                      +"Strength: "+QString::number(dc->getCurrentLvl()->listOfCharacter.at(0)->getStrength()));
         ui->progressBar_3->setRange(0, dc->getCurrentLvl()->listOfCharacter.at(1)->getMaxHP());
         ui->progressBar_4->setValue(dc->getCurrentLvl()->listOfCharacter.at(1)->getHitpoints());
         ui->progressBar_3->setFormat("Health: "+ QString::number(dc->getCurrentLvl()->listOfCharacter.at(1)->getHitpoints())
                                      +" Strength: "+QString::number(dc->getCurrentLvl()->listOfCharacter.at(1)->getStrength()));
      }
      if(dc->getCurrentLvl()->listOfCharacter.size()==3){
         ui->progressBar_2->show();
         ui->progressBar_3->show();
         ui->progressBar_4->show();
         ui->progressBar_2->setRange(0, dc->getCurrentLvl()->listOfCharacter.at(0)->getMaxHP());
         ui->progressBar_2->setValue(dc->getCurrentLvl()->listOfCharacter.at(0)->getHitpoints());
         ui->progressBar_2->setFormat("Health: "+ QString::number(dc->getCurrentLvl()->listOfCharacter.at(0)->getHitpoints())
                                      +" Strength: "+QString::number(dc->getCurrentLvl()->listOfCharacter.at(0)->getStrength()));
         ui->progressBar_3->setRange(0, dc->getCurrentLvl()->listOfCharacter.at(1)->getMaxHP());
         ui->progressBar_3->setValue(dc->getCurrentLvl()->listOfCharacter.at(1)->getHitpoints());
         ui->progressBar_3->setFormat("Health: "+ QString::number(dc->getCurrentLvl()->listOfCharacter.at(1)->getHitpoints())
                                      +" Strength: "+QString::number(dc->getCurrentLvl()->listOfCharacter.at(1)->getStrength()));
         ui->progressBar_4->setRange(0, dc->getCurrentLvl()->listOfCharacter.at(2)->getMaxHP());
         ui->progressBar_4->setValue(dc->getCurrentLvl()->listOfCharacter.at(2)->getHitpoints());
         ui->progressBar_4->setFormat("Health: "+ QString::number(dc->getCurrentLvl()->listOfCharacter.at(2)->getHitpoints())
                                      +" Strength: "+QString::number(dc->getCurrentLvl()->listOfCharacter.at(2)->getStrength()));
      }

}

void MainWindowGame::setDc(DungeonCrawler *newDc)
{
    dc = newDc;
}


void MainWindowGame::on_pushButton_10_clicked()
{
    lastInput=10;
    nextMove(lastInput);
}


void MainWindowGame::on_pushButton_11_clicked()
{
    lastInput =11;
    nextMove(lastInput);
}

