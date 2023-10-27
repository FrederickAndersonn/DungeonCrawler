#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include <QPixmap>
#include "Tile.h"
#include "Active.h"

class DungeonCrawler;
class Level;

class Levelchanger : public Tile, public Active {
 public:
  Levelchanger(Character* character, int row, int column,
               Level* destinationLevel);
  Levelchanger(int row, int col, Character* who);
  virtual Tile* onEnter(Tile* fromTile, Character* who) override;
  void attach(Passive* listener) override;
  void detach(Passive* listener)override;
  void setDestinationLevel(Level* destinationPortal);
  void setDestinationLevelchanger(Levelchanger* destinationPortal);
  Tile* onLeave(Tile* ,Character*)override;
  QPixmap* getTextureGUI()override;
  void setTextureGUI(QPixmap*)override;
  Level* getDestinationLevel();
  Levelchanger* getDestinationLevelchanger();

 protected:
  Level* destinationLevel;
  Levelchanger* destinationLevelchanger;
};


#endif // LEVELCHANGER_H
