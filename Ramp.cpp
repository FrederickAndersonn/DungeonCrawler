#include "Ramp.h"

Ramp::Ramp(): Tile("<", 0,0,nullptr)
{

}

Ramp::Ramp(int row, int col, Character* who): Tile("<",row,col, nullptr){

}

Ramp::Ramp(std::string texture, int row, int col, Character* who): Tile(texture,row,col, nullptr){

}
Tile* Ramp::onEnter(Tile* fromTile, Character* who){
    return this;
}
Tile* Ramp::onLeave(Tile* destTile, Character* who){
    return this;
}
void Ramp::setTextureGUI (QPixmap* td){
    textureGUI = td;
}
QPixmap *Ramp::getTextureGUI()
{
    return new QPixmap("../GoaManjatFinal/textures/ramp.png");
}
