#ifndef DUNGEONCRAWLERSAVER_H
#define DUNGEONCRAWLERSAVER_H
#include "attackcontroller.h"
#include "Dungeoncrawler.h"
#include "Guardcontroller.h"
#include "Level.h"
#include "Graphicalui.h"
#include "json.hpp"

class DungeonCrawlerSerializer {
 public:
  DungeonCrawlerSerializer();

  static nlohmann::json serialize(DungeonCrawler* crawler);
  static DungeonCrawler* deserialize(nlohmann::json serialized, AbstractUI* ui);

 private:
  struct LChangerConnection {
    int row;
    int col;
    int levelIndex;

    int toRow;
    int toCol;
    int toLevelIndex;

    LChangerConnection(int row, int col, int levelIndex, int toRow, int toCol,
                       int toLevelIndex)
        : row(row),
          col(col),
          levelIndex(levelIndex),
          toRow(toRow),
          toCol(toCol),
          toLevelIndex(toLevelIndex) {}
  };
};


#endif // DUNGEONCRAWLERSAVER_H
