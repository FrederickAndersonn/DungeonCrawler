#ifndef LOOTCHEST_H
#define LOOTCHEST_H

#include "Active.h"
#include "Tile.h"

class Lootchest : public Tile, public Active {
private:
    QPixmap* textureGUI;
 public:
  Lootchest(int row, int column,Character* character);
  Tile* onEnter(Tile* fromTile, Character* who) override;
  Tile* onLeave(Tile* fromTile, Character*who)override;
  QPixmap* getTextureGUI()override;
  void setTextureGUI(QPixmap*)override;
};


#endif // LOOTCHEST_H
