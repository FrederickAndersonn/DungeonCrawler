#include "Character.h"


QPixmap *Character::getTextureC()
{
    return textureC;
}

void Character::setTextureC(QPixmap *newTextureC)
{
    textureC = newTextureC;
}

int Character::getStrength() const
{
    return strength;
}

int Character::getStamina() const
{
    return stamina;
}

int Character::getHitpoints() const
{
    return hitpoints;
}

int Character::getMaxHP()
{
    maxHP = 20+(stamina*5);
    return maxHP;
}

void Character::setTexture(const std::string &newTexture)
{
    texture = newTexture;
}

void Character::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
}

Character::Character() : texture("P"), currentTile(nullptr) {
    isCharacter = true;
    stamina = 10;
    strength = 10;
    hitpoints= getMaxHP();
    textureC = new QPixmap("../GoaManjatFinal/textures/char/front/char_front_2.png");
}

Character::Character(Tile* tile, const std::string& text) : currentTile(tile), texture(text) {
    isCharacter= true;
    stamina = 10;
    strength = 10;
    hitpoints= getMaxHP();
    textureC = new QPixmap("../GoaManjatFinal/textures/char/front/char_front_2.png");
}
Character::Character(Tile* tile, int strength, int stamina):currentTile(tile), strength(strength), stamina(stamina)
{
    isCharacter= true;
    textureC = new QPixmap("../GoaManjatFinal/textures/char/front/char_front_2.png");
    hitpoints = getMaxHP();
}

std::string Character::getTexture() {

    return texture;
}

Tile* Character::getCurrentTile() const {
    return currentTile;
}

void Character::setCurrentTile(Tile* curTile) {
    Character::currentTile = curTile;
}


void Character::hit(int strength) {
  this->hitpoints -= strength;
  if (this->hitpoints < 0)
      this->hitpoints = 0;
}


bool Character::isAlive() { return hitpoints != 0; }
