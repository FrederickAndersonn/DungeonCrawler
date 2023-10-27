#include "Wall.h"

Wall::Wall():Tile("#", 0, 0, nullptr)
{
    setTextureGUI(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/wall/wall1.png"));
}

Wall::Wall(int row, int col, Character* who):Tile("#", row, col, who) {
}

Tile* Wall::onEnter(Tile* fromTile, Character* who){
    return nullptr;
}

Tile* Wall::onLeave(Tile* destTile, Character* who){
    return this;
}
void Wall::setTextureGUI (QPixmap* td){
    textureGUI = td;
}
QPixmap *Wall::getTextureGUI()
{
    return new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/wall/wall1.png");
}
