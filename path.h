#ifndef PATH_H
#define PATH_H

#include <deque>

#include "Tile.h"

class Path {
 public:
  Path();

  std::deque<Tile*> path;
};

struct PathNode {
  Tile* tile;
  PathNode* prev;
  int distance;

  PathNode() {
    tile = nullptr;
    prev = nullptr;
    distance = 0;
  };
};


#endif // PATH_H
