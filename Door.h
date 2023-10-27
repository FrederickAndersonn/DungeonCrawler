#ifndef DOOR_H
#define DOOR_H

#include "Active.h"
#include "Character.h"
#include "Passive.h"
#include "Tile.h"
#include <QPixmap>

class Door : public Tile, public Passive
{
protected:
    bool checkDoor = false;
public:
    string getTexture();
    Door(int row, int column, Character* who);
    bool getDoorStatus();
    void setDoorStatus(bool);
    bool notify (Active* source)override;
    Tile* onEnter(Tile* fromTile, Character* who)override;
    Tile* onLeave(Tile* destTile, Character* who)override;
    void setTexture(string);
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;

};
#endif // DOOR_H
