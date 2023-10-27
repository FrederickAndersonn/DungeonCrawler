#include "Portal.h"

Portal::Portal(): Tile("O",0,0,nullptr ), destTile(nullptr)
{

}

Portal::Portal(int row, int col, Character* who): Tile("O",row,col,nullptr ), destTile(nullptr)
{

}

Tile* Portal::onEnter(Tile* fromTile, Character* who){
    return destTile;
}

Tile* Portal::onLeave(Tile* destTile, Character* who){
    return this;
}

Tile *Portal::getDestTile() const
{
    return destTile;
}

void Portal::setDestTile(Tile *newDestTile)
{
    destTile = newDestTile;
}
void Portal::setTextureGUI (QPixmap* td){
    textureGUI = td;
}

QPixmap *Portal::getTextureGUI2()
{
    return new QPixmap("../GoaManjatFinal/textures/portal/portal2.png");
}
QPixmap *Portal::getTextureGUI()
{
    return new QPixmap("../GoaManjatFinal/textures/portal/portal1.png");
}
