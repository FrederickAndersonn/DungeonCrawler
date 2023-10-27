#include "Level.h"
#include "Portal.h"
#include "Floor.h"
#include "Portal.h"
#include "Wall.h"
#include "Character.h"
#include "Pit.h"
#include "Ramp.h"
#include "GuardController.h"
#include "Npc.h"
#include "Switch.h"
#include "Door.h"
#include <QVector>
#include <QPixmap>
#include "lootchest.h"
#include "attackcontroller.h"


Level::~Level() {

    for (std::vector<Tile*>& vec: veccy) {
        for (Tile*& tile: vec) {

            delete tile;
            tile = nullptr;
        }
    }
    for (Character*& character: listOfCharacter) {

        delete character;
        character = nullptr;
    }
}

int Level::getDifficulty() const
{
    return difficulty;
}

void Level::setDifficulty(int newDifficulty)
{
    difficulty = newDifficulty;
}


Level::Level(int difficulty) : maxRow(7), maxColumn(15), listOfCharacter{}, difficulty(difficulty) {

    createEmptyLevel(maxRow, maxColumn);
    if(difficulty==2){
//        createNpc1(2, 3, 2);
//        createNpc1(6,14, 2);
//        createNpc1(3, 11, 3);
    }
      createNeighbours();

}

Level::Level(int maxRow, int maxColumn): maxRow(maxRow), maxColumn(maxColumn){
    for (int i=0; i <= getMaxRow(); i++) {
        veccy.emplace_back();
        textureList.emplaceBack();
        for (int j=0; j <= getMaxColumn(); j++) {
            veccy.at(i).push_back(new Floor(i,j, nullptr));
        }
    }
//    createNpc1(3,3,3);
    createNeighbours();
}
void Level::setHuman(Character *newHuman)
{
    human = newHuman;
}

Character *Level::getHuman() const
{
    return human;
}

Level::Level() : maxRow(7), maxColumn(15), listOfCharacter{} {

    createEmptyLevel(maxRow, maxColumn);

    createNeighbours();


}
Tile* Level::getTile(int row, int col) {
    return veccy.at(row).at(col);
}

const Tile* Level::getTile(int row, int col) const {
    return veccy.at(row).at(col);
}


void Level::placeCharacter(Character* c, int row, int col) {
    Tile* tempTile = getTile(row, col);
    tempTile->setCharacter(c);
    c->setCurrentTile(tempTile);
}

int Level::getMaxRow() const {
    return maxRow;
}

int Level::getMaxColumn() const {
    return maxColumn;
}

void Level::createEmptyLevel(int rows, int columns) {

    const vector<std::string> level = {
    "################",
    "#.......#O._<..#",
    "#O....###.___..#",
    "#.....#O#......#",
    "#.......###X####",
    "#########......#",
    "#O....?##......#",
    "################",
    };

    for (int i=0; i <= getMaxRow(); i++) {
        veccy.emplace_back();
        textureList.emplaceBack();
        for (int j=0; j <= getMaxColumn(); j++) {
                if (level.at(i).at(j) == '#') {
                    veccy.at(i).push_back(new Wall(i, j, nullptr));

                }
                if (level.at(i).at(j) == '.') {
                    veccy.at(i).push_back(new Floor(i, j, nullptr));
                    //textureList[i].push_back(randomFloor(i%5));//todo: random values!
                }
                if (level.at(i).at(j) == '_') {
                    veccy.at(i).push_back(new Pit(i, j, nullptr));
                    //textureList[i].push_back(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/pit.png"));
                }
                if (level.at(i).at(j) == '<') {
                    veccy.at(i).push_back(new Ramp(i, j, nullptr));
                    //textureList[i].push_back(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/ramp.png"));
                }
                if(level.at(i).at(j) == 'O'){
                    Portal* p = new Portal(i,j,nullptr);
                    veccy.at(i).push_back(p);
                    portalList.push_back(p);
                    //textureList[i].push_back(randomPortal(i%2));
                }
                if(level.at(i).at(j) == 'X'){
                    Door* d = new Door(i,j,nullptr);
                    veccy.at(i).push_back(d);
                    doorList.push_back(d);
                }
                if(level.at(i).at(j) == '?'){
                    Switch* s= new Switch(i,j,nullptr);
                    veccy.at(i).push_back(s);
                    //textureList[i].push_back(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/switch.png"));
                    switchList.push_back(s);
                }
                if(level.at(i).at(j) == '|'){
                    Levelchanger* lc= new Levelchanger(i,j,nullptr);
                    veccy.at(i).push_back(lc);
                    lcList.push_back(lc);
                    //textureList[i].push_back(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/switch.png"));
                }
                if(level.at(i).at(j) =='L'){
                    Lootchest* loot = new Lootchest(i,j,nullptr);
                    veccy.at(i).push_back(loot);
                }
            }
        }

     portalList.at(0)->setDestTile(portalList.at(2));
     portalList.at(2)->setDestTile(portalList.at(0));
     portalList.at(1)->setDestTile(portalList.at(3));
     portalList.at(3)->setDestTile(portalList.at(1));
     switchList.at(0)->attach(doorList.at(0));
     createNeighbours();
   }


void Level::createCharacter(int row, int col) {

    listOfCharacter.push_back(new Character());
    placeCharacter(listOfCharacter.at(listOfCharacter.size() - 1), row, col);
}

void Level::createNpc(int row, int col, std::vector<int> pattern, int difficulty) {
    GuardController* npcController = new GuardController(pattern);
    Npc* npc = new Npc(nullptr, "N", npcController, difficulty);
    npc->setNpcController(npcController);
    placeCharacter(npc, row, col);
    listOfCharacter.push_back(npc);
}

void Level::createNpc1(int row, int col, int difficulty) {
    AttackController* acc;
    Npc* npc = new Npc(nullptr, "N", acc, difficulty);
    AttackController* ac = new AttackController(this, npc);
    npc->setNpcController(ac);
    placeCharacter(npc, row, col);
    listOfCharacter.push_back(npc);
}


void Level::setTextureAt(int i, int j, QPixmap *val)
{
    textureList[i][j] = val;
}

void Level::setTile(Tile *tile)
{
    delete veccy.at(tile->getRow()).at(tile->getCol());
    veccy.at(tile->getRow()).at(tile->getCol()) = tile;

}

Levelchanger* Level::createLevelchangerAt(int row, int col, Level* level) {
  delete veccy.at(row).at(col);
  Levelchanger* levelchanger = new Levelchanger(nullptr, row, col, level);
  veccy.at(row).at(col) = levelchanger;
  return levelchanger;
}

Path* Level::getPath(Tile* from, Tile* to) {
  std::unordered_set<Tile*> visited;
  std::unordered_set<PathNode*> nodes;
  std::queue<PathNode*> queue;

  PathNode* startNode = new PathNode;
  startNode->tile = from;

  queue.push(startNode);
  nodes.insert(startNode);

  PathNode* curNode = nullptr;
  PathNode* destNode = nullptr;
  while (!queue.empty()) {
    curNode = queue.front();
    queue.pop();
    if (curNode->tile == to) {
      destNode = curNode;
      break;
    }

    visited.insert(curNode->tile);
    nodes.insert(curNode);
    try {
      for (Tile* neighbour : curNode->tile->getNeighbours()) {
        if (visited.find(neighbour) == visited.end()) {
          PathNode* nextNode = new PathNode;
          nextNode->tile = neighbour;
          nextNode->prev = curNode;
          nextNode->distance = curNode->distance + 1;
          queue.push(nextNode);
          visited.insert(neighbour);
          nodes.insert(nextNode);
        }
      }
    } catch (...) {
    }
  }

  Path* path = new Path();

  while (destNode != nullptr) {
    Portal* p = dynamic_cast<Portal*>(destNode->tile);
    if (p == nullptr)
      path->path.push_front(destNode->tile);
    else
      path->path.push_front(p->getDestTile());
    destNode = destNode->prev;
  }

  if (!path->path.empty()) {
    path->path.pop_front();
  }

  for (PathNode* pathNode : nodes) {
    delete pathNode;
  }

  return path;
}
void Level::createNeighbours() {
  for (int i = 0; i <= maxRow; i++) {
     veccy.emplace_back();
    for (int j = 0; j <= maxColumn; j++) {
      Tile* curTile = this->veccy.at(i).at(j);
      curTile->neighbours.clear();
      bool isPit = typeid(*curTile) == typeid(Pit);

      for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
          if (k == i && l == j) {
            continue;
          }
          if (k >= 0 && k < maxRow && l >= 0 && l < maxColumn){
          Tile* neighbourTile = this->getTile(k, l);
          if (neighbourTile == nullptr)
              continue;
          if (isPit) {
            if (typeid(*curTile) == typeid(Ramp)) {
              curTile->neighbours.push_back(neighbourTile);
            }
            continue;
          }
          if (typeid(*neighbourTile) == typeid(Floor)) {
            curTile->neighbours.push_back(neighbourTile);
          } else if (typeid(*neighbourTile) == typeid(Wall)) {
            continue;
          } else if (typeid(*neighbourTile) == typeid(Ramp)) {
            curTile->neighbours.push_back(neighbourTile);
          } else if (typeid(*neighbourTile) == typeid(Switch)) {
            curTile->neighbours.push_back(neighbourTile);
          } else if (typeid(*neighbourTile) == typeid(Door)) {
            Door* door = dynamic_cast<Door*>(neighbourTile);
            if (door->getDoorStatus()) curTile->neighbours.push_back(neighbourTile);
          } else if (typeid(*neighbourTile) == typeid(Portal)) {
            Portal* portal = dynamic_cast<Portal*>(neighbourTile);
            curTile->neighbours.push_back(portal->getDestTile());
          } else if (typeid(*neighbourTile) == typeid(Pit)) {
            curTile->neighbours.push_back(neighbourTile);
          }
        }
      }
    }
  }
}
}
