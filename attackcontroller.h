#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "Character.h"
#include "Level.h"
#include "AbstractController.h"
#include "DungeonCrawler.h"
class DungeonCrawlerSerializer;

class AttackController : public AbstractController {
 public:
  AttackController(Level* lvl, Character* attacker);
  int move() override;

  Tile* nextTile;
  //friend class DungeonCrawlerSerializer;

 protected:
  Level* level;
  Character* attacker;
};

#endif // ATTACKCONTROLLER_H
