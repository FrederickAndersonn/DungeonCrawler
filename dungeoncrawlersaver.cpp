#include "dungeoncrawlersaver.h"
#include "mainwindow.h"
#include <vector>
#include "Wall.h"
#include "Ramp.h"
#include "Pit.h"
#include "DungeonCrawler.h"
#include "Npc.h"
DungeonCrawlerSerializer::DungeonCrawlerSerializer() {}

nlohmann::json DungeonCrawlerSerializer::serialize(DungeonCrawler* crawler) {
nlohmann::json levelsJson;
nlohmann::json mainCharacter;

  DoubleLinkedList<Level*> levels = crawler->levels;
  if(crawler->getCurrentChar()->getCurrentTile()!=nullptr){
      mainCharacter["col"]=crawler->getCurrentChar()->getCurrentTile()->getCol();
      mainCharacter["row"]=crawler->getCurrentChar()->getCurrentTile()->getRow();
      mainCharacter["hitpoints"]=crawler->getCurrentChar()->getHitpoints();
      levelsJson["mainCharacter"].push_back(mainCharacter);
  }
  for(auto& level: levels){
     nlohmann::json lvlJson;
     lvlJson["meta"]["cols"] = level->getMaxColumn();
     lvlJson["meta"]["row"] = level->getMaxRow();
     for(auto& npc: level->listOfCharacter){
         nlohmann::json nonPlayer;
         nonPlayer["col"]=npc->getCurrentTile()->getCol();
         nonPlayer["row"]=npc->getCurrentTile()->getRow();
         nonPlayer["hitpoints"]=npc->getHitpoints();
         lvlJson["npc"].push_back(nonPlayer);
     }
     nlohmann::json tilesJSON = nlohmann::json::array();
     for(int i = 0; i<=level->getMaxRow(); i++){
         for(int j = 0; j<=level->getMaxColumn(); j++){
                Tile* curTile = level->getTile(i,j);
                nlohmann::json tileJSON;
                tileJSON["texture"] = curTile->getTexture();
                tileJSON["row"] = curTile->getRow();
                tileJSON["col"] = curTile->getCol();
                if (typeid(*curTile) == typeid(Floor)) {
                } else if (typeid(*curTile) == typeid(Wall)) {
                } else if (typeid(*curTile) == typeid(Ramp)) {
                } else if (typeid(*curTile) == typeid(Switch)) {
               Active* switchTile = dynamic_cast<Active*>(curTile);
               } else if (typeid(*curTile) == typeid(Door)) {
                 Door* door = dynamic_cast<Door*>(curTile);
                 tileJSON["isOpen"] = door->getDoorStatus();
               } else if (typeid(*curTile) == typeid(Portal)) {
                 Portal* portal = dynamic_cast<Portal*>(curTile);
                 Tile* destination = portal->getDestTile();

                 tileJSON["destRow"] = destination->getRow();
                 tileJSON["destCol"] = destination->getCol();
               } else if (typeid(*curTile) == typeid(Pit)) {
               } else if (typeid(*curTile) == typeid(Levelchanger)) {
               Levelchanger* changer = dynamic_cast<Levelchanger*>(curTile);
               Levelchanger* destination = changer->getDestinationLevelchanger();
               tileJSON["texture"] = "Levelchanger";
               tileJSON["toLevel"] = levels.indexAt(changer->getDestinationLevel());
               tileJSON["destRow"] = destination->getRow();
               tileJSON["destCol"] = destination->getCol();
               }

               tilesJSON.push_back(tileJSON);
               }
             }
     lvlJson["tiles"]=tilesJSON;
     levelsJson["level"].push_back(lvlJson);
  }
return levelsJson;

}

DungeonCrawler* DungeonCrawlerSerializer::deserialize(nlohmann::json serialized,
                                                      AbstractUI* ui) {
    int levelIndex = 0;
    int currentLevelIndex = 0;
    int i =0;
    int j = 0;
    int mainCharRow = 0;
    int mainCharCol = 0;
    int mainCharHp =0;

  std::vector<Level*> levels;
  std::vector<Portal*> portalList;
  std::vector<Switch*> switchList;
  std::vector<Door*> doorList;
  std::vector<LChangerConnection*> connections;
  Character* mainCharacter = new Character(nullptr, "p");
  Level* lvl = new Level(2);
  DungeonCrawler* dungeonCrawler = new DungeonCrawler(ui,lvl,mainCharacter);
  for (const auto& levelJSON : serialized["level"]) {
    Level* level =
        new Level(levelJSON["meta"]["row"], levelJSON["meta"]["cols"]);

    for (const auto& tileJSON : levelJSON["tiles"]) {
      Tile* curTile = level->getTile(tileJSON["row"], tileJSON["col"]);
      std::string texture = tileJSON["texture"];
      if(curTile->hasCharacter()){
          if(typeid(curTile)==typeid(Portal)){
              Portal* portal = new Portal(tileJSON["row"], tileJSON["col"], nullptr);
              portalList.push_back(portal);
          }
      }
      if (texture == ".") {
        level->setTile(new Floor(tileJSON["row"], tileJSON["col"], nullptr));
      } else if (texture == "#") {
        level->setTile(new Wall(tileJSON["row"], tileJSON["col"],nullptr));
      } else if (texture == "<") {
        level->setTile(new Ramp (tileJSON["row"], tileJSON["col"],nullptr));
      } else if (texture == "_") {
        level->setTile(new Pit(tileJSON["row"], tileJSON["col"],nullptr));
      } else if (texture == "?") {
        Switch* switchTile =
            new Switch(tileJSON["row"], tileJSON["col"],nullptr);
        level->setTile(switchTile);
        switchList.push_back(switchTile);
      } else if (texture == "X") {
        Door* door = new Door(tileJSON["row"], tileJSON["col"],nullptr);
        door->setDoorStatus(tileJSON["isOpen"]);
        level->setTile(door);
        doorList.push_back(door);
      } else if (texture == "O") {
        Portal* portal = new Portal(tileJSON["row"], tileJSON["col"], nullptr);
        portalList.push_back(portal);
        level->setTile(portal);

      } else if (texture == "Levelchanger") {
        Levelchanger* levelchanger = new Levelchanger(nullptr, tileJSON["row"],
                                                      tileJSON["col"], nullptr);

        dungeonCrawler->addLevel(level);
        levelchanger->attach(dungeonCrawler);
        level->setTile(levelchanger);
        connections.push_back(new LChangerConnection(
            tileJSON["row"], tileJSON["col"], levelIndex, tileJSON["destRow"],
            tileJSON["destCol"], tileJSON["toLevel"]));
      } else if (texture == "Lootchest") {
        Lootchest* lootchest =
            new Lootchest(tileJSON["row"], tileJSON["col"],nullptr);
        lootchest->attach(dungeonCrawler);
        level->setTile(lootchest);
      }
      else if(texture == "P" || texture =="p"){
        currentLevelIndex=levelIndex;
      }
    }
    if(!portalList.empty()){
        portalList.at(0)->setDestTile(portalList.at(2));
        portalList.at(2)->setDestTile(portalList.at(0));
        portalList.at(1)->setDestTile(portalList.at(3));
        portalList.at(3)->setDestTile(portalList.at(1));
    }
    if(!portalList.empty()&&!switchList.empty()){
        switchList.at(0)->attach(doorList.at(0));
        switchList.clear();
        doorList.clear();
    }

    // Add Characters
    for (const auto& characterJSON : levelJSON["npc"]) {
    int npcCharHp = characterJSON["hitpoints"];
      AttackController* acc;
      Npc* npc = new Npc(nullptr, "N", acc, 2);
      AttackController* ac = new AttackController(level, npc);
      npc->setNpcController(ac);
      npc->setHitpoints(npcCharHp);
      level->placeCharacter(npc, characterJSON["row"],
              characterJSON["col"]);
      level->listOfCharacter.push_back(npc);
    }

    level->createNeighbours();
    levels.push_back(level);
    ++levelIndex;

  }

  // Attach Levelchanger
  for (const auto& connection : connections) {
    Level* fromLevel = levels.at(connection->levelIndex);
    Level* toLevel = levels.at(connection->toLevelIndex);

    Levelchanger* from = dynamic_cast<Levelchanger*>(
        fromLevel->getTile(connection->row, connection->col));
    Levelchanger* to = dynamic_cast<Levelchanger*>(
        toLevel->getTile(connection->toRow, connection->toCol));

    from->setDestinationLevel(toLevel);
    from->setDestinationLevelchanger(to);

    to->setDestinationLevel(fromLevel);
    to->setDestinationLevelchanger(from);

  }

  dungeonCrawler->setCurrentLvl(levels.at(currentLevelIndex));
  for(const auto &character: serialized["mainCharacter"]) {
       mainCharRow = character["row"];
       mainCharCol = character["col"];
       mainCharHp = character["hitpoints"];
  }

  levels.at(currentLevelIndex)->setHuman(mainCharacter);
  mainCharacter->setHitpoints(mainCharHp);
  levels.at(currentLevelIndex)->placeCharacter(mainCharacter, mainCharRow,mainCharCol);

  return dungeonCrawler;
}
