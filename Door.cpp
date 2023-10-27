#include "Door.h"

QPixmap *Door::getTextureGUI()
{
   return textureGUI;
}

void Door::setTexture(string t)
{
    texture = t;
}

void Door::setTextureGUI (QPixmap* td){
    textureGUI = td;
}

Door::Door(int row, int column, Character* character)

    : Tile{"X", row, column, character}{
    checkDoor= false;
    textureGUI= new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/doors/door1.png");
}

bool Door::getDoorStatus()
{
    return checkDoor;
}
void Door::setDoorStatus(bool newDoorStatus)
{
    checkDoor = newDoorStatus;
}

bool Door::notify (Active* source)
{
    checkDoor = !checkDoor;
    if(checkDoor){
        setTexture("/");
        setTextureGUI(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/doors/door2.png"));
    }
    else{
        setTexture("X");
        setTextureGUI(new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/doors/door1.png"));
    }

    return checkDoor;
}

Tile* Door::onEnter(Tile* fromTile, Character* who)
{
    if(checkDoor==false)
        return nullptr;
    else{
        return this;
    }
}
Tile* Door::onLeave(Tile* destTile, Character* who)
{
    return this;
}
