#include "DungeonCrawler.h"
#include "AbstractUI.h"
#include "Character.h"
#include "Npc.h"
#include "TerminalUI.h"
#include "Tile.h"
#include <iostream>
#include "GraphicalUI.h"
#include "dungeoncrawlersaver.h"

DungeonCrawler::DungeonCrawler() : currentLvl(nullptr), currentAbstractUI(nullptr), currentChar(nullptr) {
    levelChanged=false;

}

void DungeonCrawler::setCurrentAbstractUI(AbstractUI* currAbstractUI) { currentAbstractUI = currAbstractUI; }

void DungeonCrawler::setCurrentLvl(Level* currLvl) { DungeonCrawler::currentLvl = currLvl; }

void DungeonCrawler::turn(int movingDir){
    if(getCurrentChar()->getHitpoints()==0){
        gameover=true;
    }
    if(gameover==true){
         mwgl->show();
         mwg->close();

     }
    else if (humansWon==true){
        mwgw->show();
        mwg->close();
    }
    else{
        if(getCurrentChar()==nullptr){
            gameover=true;
        }
        if(gameover==true){
             mwgl->show();
             mwg->close();

         }
    switchMove(movingDir, getCurrentChar()->getCurrentTile(), getCurrentChar());
    for (auto character: getCurrentLvl()->listOfCharacter) {
        if(character->getCurrentTile()!=nullptr){
        Npc* npc = dynamic_cast<Npc*>(character);
        movingDir = npc->getNpcController()->move();
        switchMove2(movingDir, npc->getCurrentTile(), npc);}
    }

}
}


DungeonCrawler::DungeonCrawler(AbstractUI* abstractUI, Level* level, Character* character)
    : currentAbstractUI{abstractUI}, currentLvl{level}, currentChar{character}{
    DungeonCrawler::currentAbstractUI->setDungeonCrawler(this);
    currentLvl->placeCharacter(character, 1, 1);
}

AbstractUI* DungeonCrawler::getCurrentAbstractUi() const { return currentAbstractUI; }

void DungeonCrawler::setCurrentAbstractUi(AbstractUI* currentAbstractUi) { currentAbstractUI = currentAbstractUi; }

Level* DungeonCrawler::getCurrentLvl() const { return currentLvl; }

Character* DungeonCrawler::getCurrentChar() const { return currentChar; }

void DungeonCrawler::setCurrentChar(Character* currentChar) { DungeonCrawler::currentChar = currentChar; }

void DungeonCrawler::switchMove(int movingDir, Tile* currentTile, Character* character) {

    Tile* nextTile{nullptr};

    switch (movingDir) {

        case 1: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() + 1).at(currentTile->getCol() - 1);              
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("../GoaManjatFinal/textures/char/left/char_left_1.png"));
            break;
        }

        case 2: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() + 1).at(currentTile->getCol());
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/front/char_front_1.png"));
            break;
        }

        case 3: {

                nextTile = currentLvl->veccy.at(currentTile->getRow() + 1).at(currentTile->getCol() + 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/right/char_right_1.png"));
            break;
        }


        case 4: {

                nextTile = currentLvl->veccy.at(currentTile->getRow()).at(currentTile->getCol() - 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/left/char_left_1.png"));
            break;
        }


        case 5: {
            character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/front/char_front_2.png"));
            break;

        }


        case 6: {
                nextTile = currentLvl->veccy.at(currentTile->getRow()).at(currentTile->getCol() + 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/right/char_right_1.png"));
            break;
        }

        case 7: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() - 1).at(currentTile->getCol() - 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/right/char_right_1.png"));
            break;
        }


        case 8: {
            if (currentTile->getRow() > 0) {
                nextTile = currentLvl->veccy.at(currentTile->getRow() - 1).at(currentTile->getCol());
                currentTile->moveTo(nextTile, character);
            }
            character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/back/char_back_1.png"));
            break;
        }

        case 9: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() - 1).at(currentTile->getCol() + 1);
                currentTile->moveTo(nextTile, character);
           character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/char/left/char_left_1.png"));
            break;
        }
        case 10: {
        saveProgress();
        break;
    }
        case 11:{
        break;
    }

        default: {
            break;
        }
    }
}

void DungeonCrawler::switchMove2(int movingDir, Tile* currentTile, Character* character) {

    Tile* nextTile{nullptr};

    switch (movingDir) {

        //move down and left
        case 1: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() + 1).at(currentTile->getCol() - 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_left.png"));
            break;
        }
            //move down
        case 2: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() + 1).at(currentTile->getCol());
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_left.png"));
            break;
        }

        case 3: {

                nextTile = currentLvl->veccy.at(currentTile->getRow() + 1).at(currentTile->getCol() + 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png"));
            break;
        }

            //move left
        case 4: {

                nextTile = currentLvl->veccy.at(currentTile->getRow()).at(currentTile->getCol() - 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_left.png"));
            break;
        }


        case 5: {
            character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png"));
            break;

        }


        case 6: {
                nextTile = currentLvl->veccy.at(currentTile->getRow()).at(currentTile->getCol() + 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png"));
            break;
        }

        case 7: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() - 1).at(currentTile->getCol() - 1);
                currentTile->moveTo(nextTile, character);
                character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_left.png"));
            break;
        }

        case 8: {
            if (currentTile->getRow() > 0) {
                nextTile = currentLvl->veccy.at(currentTile->getRow() - 1).at(currentTile->getCol());
                currentTile->moveTo(nextTile, character);
            }
            character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png"));
            break;
        }

        case 9: {
                nextTile = currentLvl->veccy.at(currentTile->getRow() - 1).at(currentTile->getCol() + 1);
                currentTile->moveTo(nextTile, character);
            character->setTextureC(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png"));
            break;
        }

        default: {
            break;
        }
    }
}

void DungeonCrawler::addLevel(Level* level) {
  if (!levels.find(level)) {
    levels.push_back(level);
  }
}

bool DungeonCrawler::notify(Active* source) {
    Levelchanger* levelchanger = dynamic_cast<Levelchanger*>(source);
      if (levelchanger != nullptr) {
        this->getCurrentAbstractUi()->reset();
        currentLvl = levelchanger->getDestinationLevel();
        Levelchanger* destinationTile = levelchanger->getDestinationLevelchanger();
        Character* switchChar = levelchanger->getCharacter();
        switchChar->getCurrentTile()->setCharacter(nullptr);
        currentLvl->placeCharacter(switchChar, destinationTile->getRow(),
                                         destinationTile->getCol());
        GraphicalUI* gui = dynamic_cast<GraphicalUI*>(currentAbstractUI);
        gui->setLevel(currentLvl);//to do
        currentLvl->setHuman(switchChar);
        mwg->textureList.clear();
      }

  Lootchest* lootchest = dynamic_cast<Lootchest*>(source);
  if (lootchest != nullptr) {
    humansWon = true;
    return true;
  }
}

MainWindowGame *DungeonCrawler::getMwg() const
{
    return mwg;
}

void DungeonCrawler::setMwg(MainWindowGame *newMwg)
{
    mwg = newMwg;
}

void DungeonCrawler::setMwgw(MainWindowGameWon *newMwgw)
{
    mwgw = newMwgw;
}

void DungeonCrawler::setMwgl(MainWindowGameLost *newMwgl)
{
    mwgl = newMwgl;
}


DungeonCrawler::DungeonCrawler(Character* currChar)
    : currentAbstractUI(new TerminalUI()), currentLvl(new Level()), currentChar(currChar)

{
    currentAbstractUI->setDungeonCrawler(this);
}
void DungeonCrawler::placePlayer() {
    currentLvl->placeCharacter(currentChar, 1,1);
    currentLvl->setHuman(currentChar);
}

bool DungeonCrawler::saveProgress() {
  std::ofstream myfile;
  myfile.open(
   "/Users/frederickanderson/GoaManjatFinal/savefile.json",
      std::ofstream::trunc);
  myfile << DungeonCrawlerSerializer::serialize(this).dump(2);
  myfile.close();
  return true;
}

