#include "Switch.h"
#include "Active.h"

Switch::Switch(const int row, const int column, Character* character)
    : Floor ("?", row, column, character), Active() {
}

Tile* Switch::onEnter(Tile* fromTile, Character* who) {
    activate();
    return this;
}

Tile* Switch::onLeave(Tile* destTile, Character* who) {
    return this;
}

void Switch::attach(Passive* passive) {
    for (Passive* tempPtr: listOfPassiveObjects) {
        if (tempPtr == passive) {
            throw std::runtime_error{"Cannot attach"};
        }
    }
    listOfPassiveObjects.push_back(passive);
}

void Switch::detach(Passive* passive) {
    for (int i = 0; i < listOfPassiveObjects.size(); ++i) {
        if (listOfPassiveObjects.at(i) == passive) {
            listOfPassiveObjects.erase(listOfPassiveObjects.begin() + i);
        }
    }
}
void Switch::setTextureGUI (QPixmap* td){
    textureGUI = td;
}
QPixmap *Switch::getTextureGUI()
{
    return new QPixmap("../GoaManjatFinal/textures/switch.png");;
}
