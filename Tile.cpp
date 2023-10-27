#include "Tile.h"
#include "Character.h"

std::string Tile::getTexture() const {
    if (character == nullptr) {
        return texture;
    }
    return character->getTexture();
}

Character* Tile::getCharacter(){
    return character;
}

int Tile::getRow() const {
    return row;
}

int Tile::getCol() const {
    return col;
}

void Tile::setCharacter(Character* pCharacter) {
    Tile::character = pCharacter;
}

Tile::Tile() : texture(" "), row(0), col(0), character{nullptr} {}


Tile::Tile(const string texture, const int row, const int col,
           Character* character)
    : texture{texture}, row(row), col(col), character(character) {
}


bool Tile::moveTo(Tile* destTile, Character* who) {

    if (destTile == nullptr) {
      return false;
    }

    Tile *leftTile = this->onLeave(destTile, who);
    if (leftTile == nullptr) {
      return false;
    }

    Tile *enteredTile = destTile->onEnter(leftTile, who);
    if (enteredTile == nullptr) {
      return false;
    }

    if (enteredTile->hasCharacter()) {
      if (!initFight(who, enteredTile->getCharacter())) {//if no one dead
        return false;
      }
    }
    enteredTile->setCharacter(who);
    leftTile->removeCharacter();
    who->setCurrentTile(enteredTile);
    return true;

}

bool Tile::hasCharacter()
{
    if(this->getCharacter() != nullptr)
        return true;
    return false;
}


void Tile::setTexture(string texture) {
    Tile::texture = texture;
}

bool Tile::initFight(Character *attacker, Character *defender) {
  if (attacker->isCharacter == defender->isCharacter) {
    return false;
  }

  defender->hit(attacker->getStrength());
  if (!defender->isAlive()) {
    defender->getCurrentTile()->removeCharacter();
    defender->setCurrentTile(nullptr);
    return true;
  }

  attacker->hit(defender->getStrength());
  if (!attacker->isAlive()) {
    attacker->getCurrentTile()->removeCharacter();
    attacker->setCurrentTile(nullptr);
  }
  return false;
}

void Tile::removeCharacter() { this->character = nullptr; }


