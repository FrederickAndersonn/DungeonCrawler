#include "lootchest.h"
#include "Character.h"

Lootchest::Lootchest(int row, int column, Character* character)
    : Tile("Lootchest", row, column, character) {}

Tile *Lootchest::onEnter(Tile *fromTile, Character *who) {
  if (who->isCharacter)
      activate();
  return this;
}

Tile *Lootchest::onLeave(Tile *fromTile, Character *who)
{
    return this;
}

QPixmap *Lootchest::getTextureGUI()
{
    return new QPixmap("../GoaManjatFinal/textures/chest.png");
}
void Lootchest::setTextureGUI (QPixmap* td){
    textureGUI=td;
}


