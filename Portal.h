#ifndef PORTAL_H
#define PORTAL_H

#include "Tile.h"

class Portal:public Tile
{
private:
    Tile* destTile;
public:
    Portal();
    Portal(int, int, Character*);
    ~Portal()override=default;
    Tile* onEnter(Tile* fromTile, Character*)override;
    Tile* onLeave(Tile*, Character*)override;
    Tile *getDestTile() const;
    void setDestTile(Tile *newDestTile);
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;
    QPixmap* getTextureGUI2();

};

#endif // PORTAL_H
