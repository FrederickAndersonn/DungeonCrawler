#ifndef RAMP_H
#define RAMP_H

#include "Tile.h"

class Ramp: public Tile
{
public:
    Ramp();
    Ramp(int, int, Character*);
    Ramp(std::string, int, int, Character*);
    ~Ramp() = default;
    Tile* onEnter(Tile*, Character*)override;
    Tile* onLeave(Tile*, Character*)override;
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;

};

#endif // RAMP_H
