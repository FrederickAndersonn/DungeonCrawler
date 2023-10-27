#ifndef WALL_H
#define WALL_H

#include "Tile.h"

class Wall: public Tile
{
public:
    Wall();
    Wall(int, int ,Character*);
    ~Wall() override= default;
    Tile* onEnter(Tile*, Character*)override;
    Tile* onLeave(Tile*, Character*)override;
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;

};

#endif // WALL_H
