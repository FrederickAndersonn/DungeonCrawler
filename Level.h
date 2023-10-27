#ifndef LEVEL_H
#define LEVEL_H

#include <array>
#include <vector>
#include <QVector>
#include <QPixmap>
#include "Door.h"
#include "Portal.h"
#include "Switch.h"
#include "levelchanger.h"
#include "path.h"
#include <queue>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class AttackController;

class Tile;

class Character;

class Portal;


class Level {

protected:
    const int maxRow;

    const int maxColumn;

    int difficulty;

    Character* human;

public:
    Level();
    Level(int maxRow, int maxColumn);
    Level(int difficulty);
    virtual ~Level();
    Tile* getTile(int row, int col);
    const Tile* getTile(int row, int col) const;
    std::vector<std::vector<Tile*>> veccy;
    std::vector<Character*> listOfCharacter;
    QVector<QVector<QPixmap*>> textureList;
    void placeCharacter(Character* c, int row, int col);
    void createEmptyLevel(int rows, int columns);
    void createCharacter(int row, int col);
    void createNpc(int row, int col, std::vector<int> pattern, int);
    void createNpc1(int row, int col, int);
    int getMaxRow() const;
    int getMaxColumn() const;
    vector<Portal*> portalList;
    vector<Door*> doorList;
    vector<Switch*> switchList;
    vector<Levelchanger*> lcList;
    void setTextureAt(int,int,QPixmap*);
    void setTile(Tile* tile);

    int getDifficulty() const;
    void setDifficulty(int newDifficulty);

    Levelchanger* createLevelchangerAt(int row, int col, Level* level);

    Path* getPath(Tile* from, Tile* to);
    void createNeighbours();
    void setHuman(Character *newHuman);
    Character *getHuman() const;
};


#endif // LEVEL_H
