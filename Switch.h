#ifndef SWITCH_H
#define SWITCH_H

#include "Tile.h"
#include "Floor.h"
#include "Active.h"

class Switch : public Floor, Active {

public:
    Switch() = delete;
    Switch(const int row, const int column, Character* character);
    ~Switch() = default;
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    void attach(Passive* passive) override;
    void detach(Passive* passive) override;
    QPixmap *getTextureGUI() override;
    void setTextureGUI(QPixmap*) override;

};
#endif // SWITCH_H
