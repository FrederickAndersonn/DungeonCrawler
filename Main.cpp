#include <QCoreApplication>
#include "Active.h"
#include "Character.h"
#include "Door.h"
#include "DungeonCrawler.h"
#include "Floor.h"
#include "Level.h"
#include "Pit.h"
#include "Portal.h"
#include "Ramp.h"
#include "Switch.h"
#include "TerminalUI.h"
#include "Tile.h"
#include "Wall.h"
#include "mainwindow.h"
#include "mainwindowgamewon.h"
#include "mainwindowgamelost.h"
#include "mainwindowgame.h"
#include "lootchest.h"
#include "doublelinkedlist.h"
#include <iostream>
#include <json.hpp>
#include "dungeoncrawlersaver.h"
#include <QApplication>

int main(int argc, char *argv[])try
{
    QApplication a (argc, argv);
//    MainWindow* w = new MainWindow;
//    DoubleLinkedList<Levelchanger*> dll;
//    MainWindowGameWon* mwgw = new MainWindowGameWon;
//    MainWindowGameLost* mwgl = new MainWindowGameLost;
//    GraphicalUI* gui = new GraphicalUI;
//    Level* level = new Level(2);
//    Level* level2 = new Level(8,7);
//    Level* level3 = new Level (10,15);
//    Lootchest* loot = new Lootchest(6,7, nullptr);
//    level3->setTile(loot);
//    Character* character = new Character(nullptr, "P");
//    DungeonCrawler* dg = new DungeonCrawler(gui,level,character);
//    MainWindowGame mg(gui, dg);
//    gui->setMg(&mg);
//    dg->setMwg(&mg);
//    dg->setMwgw(mwgw);
//    dg->setMwgl(mwgl);
//    Levelchanger* l1 = level->createLevelchangerAt(3, 1, level2);
//    Levelchanger* l2 = level2->createLevelchangerAt(7, 7, level);
//    Levelchanger* l3 = level2->createLevelchangerAt(5, 2, level3);
//    Levelchanger* l4 = level3->createLevelchangerAt(10, 15, level2);

//    l1->setDestinationLevelchanger(l2);
//    l2->setDestinationLevelchanger(l1);
//    l3->setDestinationLevelchanger(l4);
//    l4->setDestinationLevelchanger(l3);

//    dll.push_back(l1);
//    dll.push_back(l2);
//    dll.push_back(l3);
//    dll.push_back(l4);
//    for(auto& i : dll){
//        i->attach(dg);
//    }
//    loot->attach(dg);
//    w->show();
//    w->setToMain(&mg);
//    dg->placePlayer();
//    dg->getCurrentAbstractUi()->draw(dg->getCurrentLvl());

    std::ifstream myfile(
          "/Users/frederickanderson/GoaManjatFinal/start.json");
      nlohmann::json dungeoncrawlerJSON;
      myfile >> dungeoncrawlerJSON;
      myfile.close();
    GraphicalUI* gui = new GraphicalUI;
    DungeonCrawler* dg =
          DungeonCrawlerSerializer::deserialize(dungeoncrawlerJSON, gui);
    MainWindow* w = new MainWindow;
    DoubleLinkedList<Levelchanger*> dll;
    MainWindowGameWon* mwgw = new MainWindowGameWon;
    MainWindowGameLost* mwgl = new MainWindowGameLost;
    MainWindowGame mg(gui, dg);
    gui->setMg(&mg);
    dg->setMwg(&mg);
    dg->setMwgw(mwgw);
    dg->setMwgl(mwgl);
    dg->getCurrentAbstractUi()->draw(dg->getCurrentLvl());
    mg.show();


   return a.exec();
}
 catch (std::exception& e) {
    std::cerr<<e.what()<<"\n";
}
