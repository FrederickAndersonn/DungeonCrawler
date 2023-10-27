#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#include <string>
#include "Passive.h"
#include "doublelinkedlist.h"
#include "levelchanger.h"
#include "lootchest.h"
#include "mainwindowgame.h"
#include "mainwindowgamewon.h"
#include "mainwindowgamelost.h"
#include <fstream>
class Tile;

class Level;

class Character;

class AbstractUI;


class DungeonCrawler:public Passive {

public:
    DungeonCrawler();
    DungeonCrawler(AbstractUI*, Level*, Character*);
    DungeonCrawler(Character*);
    void placePlayer();
    void setCurrentAbstractUI(AbstractUI* currentAbstractUI);
    void setCurrentLvl(Level* currentLvl);
    void turn(int movingDir);
    AbstractUI* getCurrentAbstractUi() const;
    void setCurrentAbstractUi(AbstractUI* currentAbstractUi);
    Level* getCurrentLvl() const;
    Character* getCurrentChar() const;
    void switchMove(int moveingDir, Tile* currentTile, Character* character);
    void switchMove2(int moveingDir, Tile* currentTile, Character* character);
    void setCurrentChar(Character* currentChar);
    void addLevel(Level* level);
    DoubleLinkedList<Level*> levels;
    bool notify(Active* source);

    MainWindowGame *getMwg() const;
    void setMwg(MainWindowGame *newMwg);

    void setMwgw(MainWindowGameWon *newMwgw);

    void setMwgl(MainWindowGameLost *newMwgl);

    bool saveProgress();

private:
    AbstractUI* currentAbstractUI;
    Level* currentLvl;
    Character* currentChar;
    bool gameover;
    bool levelChanged;
    bool humansWon;
    MainWindowGame* mwg;
    MainWindowGameWon* mwgw;
    MainWindowGameLost* mwgl;

};


#endif // DUNGEONCRAWLER_H
