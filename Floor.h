#ifndef FLOOR_H
#define FLOOR_H

#include "Tile.h"

class Floor:public Tile
{
public:
    Floor();
    Floor(int, int, Character*);
    Floor(std::string,int, int, Character*);
    ~Floor()override = default;
    virtual Tile* onEnter(Tile*, Character*)override;
    virtual Tile* onLeave(Tile*, Character*)override;
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;

};

#endif // FLOOR_H
