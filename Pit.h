#ifndef PIT_H
#define PIT_H

#include "Tile.h"

class Pit:public Tile
{
public:
    Pit();
    Pit(int, int, Character*);
    Pit(std::string, int, int, Character*);
    ~Pit() = default;
    Tile* onEnter(Tile*, Character*)override;
    Tile* onLeave(Tile*, Character*)override;
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;

};

#endif // PIT_H
