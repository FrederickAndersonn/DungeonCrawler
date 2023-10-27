#include "Pit.h"

Pit::Pit(): Tile("_",0,0,nullptr)
{

}

Pit::Pit(int row, int col, Character * who): Tile("_",row, col,who){}

Pit::Pit(std::string texture, int row, int col, Character* who):Tile(texture,row, col,who){}

Tile *Pit::onEnter(Tile *fromTile, Character *who)
{
    return this;
}


Tile *Pit::onLeave(Tile* destTile, Character * who)
{
    if(typeid(*destTile) == typeid(Pit))
          return this;
      else if(destTile->getTexture() == "<")
          return this;
      else
          return nullptr;
}
void Pit::setTextureGUI (QPixmap* td){
    textureGUI = td;
}
QPixmap *Pit::getTextureGUI()
{
    return new QPixmap("../GoaManjatFinal/textures/pit.png");
}
