#include "levelchanger.h"

#include "DungeonCrawler.h"

#include "Passive.h"
#include "Character.h"

Levelchanger::Levelchanger(Character *character, int row, int column,
                           Level *destinationLevel)
    : Tile("Levelchanger", row, column, character),
      destinationLevel(destinationLevel) {}
Levelchanger::Levelchanger(int row, int col, Character* who): Tile("|",row,col,nullptr ), destinationLevel(destinationLevel)
{
}
Tile *Levelchanger::onEnter(Tile *fromTile, Character *who) {
  if (who->isCharacter) {
    character = who;
    setTexture("Levelchanger");
    activate();
  }
  return nullptr;
}

void Levelchanger::attach(Passive *passive) {
    for (Passive* tempPtr: listOfPassiveObjects) {
        if (tempPtr == passive) {
            throw std::runtime_error{"Cannot attach"};
        }
    }
    listOfPassiveObjects.push_back(passive);
    DungeonCrawler *dungeonCrawler = dynamic_cast<DungeonCrawler *>(passive);
    if (dungeonCrawler != nullptr && destinationLevel != nullptr) {
      dungeonCrawler->addLevel(destinationLevel);
}
}
void Levelchanger::detach(Passive* listener){}


void Levelchanger::setDestinationLevel(Level *destinationLevel) {
  this->destinationLevel = destinationLevel;
}

void Levelchanger::setDestinationLevelchanger(
    Levelchanger *destinationLevelchanger) {
    this->destinationLevelchanger = destinationLevelchanger;
}

Tile *Levelchanger::onLeave(Tile *, Character *)
{
    setTexture("Levelchanger");
    return this;
}

Level *Levelchanger::getDestinationLevel() { return destinationLevel; }

Levelchanger *Levelchanger::getDestinationLevelchanger() {
  return destinationLevelchanger;
}

QPixmap *Levelchanger::getTextureGUI()
{
    return new QPixmap("../GoaManjatFinal/textures/levelchanger.png");
}
void Levelchanger::setTextureGUI (QPixmap* td){
    textureGUI = td;
}
