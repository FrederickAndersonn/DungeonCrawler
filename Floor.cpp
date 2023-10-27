#include "Floor.h"

Floor::Floor():Tile(".", 0,0,nullptr)
{
    if(hasCharacter()){
        setTexture("p");
    }
}

Floor::Floor(int row, int col, Character* who):Tile(".", row,col,who)
{
    if(hasCharacter()){
        setTexture("p");
    }
}
Floor::Floor(std::string texture,int row, int col, Character* who):Tile(texture, row,col,who)
{
    if(hasCharacter()){
        setTexture("p");
    }
}

Tile* Floor::onEnter(Tile* fromTile, Character* who){
    return this;
}

Tile* Floor::onLeave(Tile* destTile, Character* who){
    return this;
}
void Floor::setTextureGUI (QPixmap* td){
    textureGUI = td;
}
QPixmap *Floor::getTextureGUI()
{
    int randomnumber = rand()%4;
    if(randomnumber==0)
        return new QPixmap("../GoaManjatFinal/textures/floor/floor1.png");
    if(randomnumber==1)
        return new QPixmap("../GoaManjatFinal/textures/floor/floor2.png");
    if(randomnumber==2)
        return new QPixmap("../GoaManjatFinal/textures/floor/floor3.png");
    if(randomnumber==3)
        return new QPixmap("../GoaManjatFinal/textures/floor/floor4.png");
    if(randomnumber==4)
        return new QPixmap("../GoaManjatFinal/textures/floor/floor5.png");
}
