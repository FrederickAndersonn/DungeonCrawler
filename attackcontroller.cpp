#include "attackcontroller.h"

#include "paths.h"

AttackController::AttackController(Level* lvl, Character *attacker)
    : level(lvl), attacker(attacker), nextTile(nullptr) {}

int AttackController::move() {
  Path *path =
level->getPath(attacker->getCurrentTile(), level->getHuman()->getCurrentTile());
  if (path->path.empty()) {
    return 5;
  }

  nextTile = path->path.front();
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==1 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==0)){
      return 8;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==1 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==1)){
      return 7;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==0 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==1)){
      return 4;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==-1 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==0)){
      return 2;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==-1 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==-1)){
      return 3;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==0 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==-1)){
      return 6;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==-1 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==1)){
      return 1;
  }
  if((attacker->getCurrentTile()->getRow()-nextTile->getRow())==1 &&(attacker->getCurrentTile()->getCol()-nextTile->getCol()==-1)){
      return 9;
  }
  return 5;
}
