#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

class DungeonCrawler;
#include "Level.h"

class AbstractUI {

public:
    virtual ~AbstractUI() = default;
    virtual void draw(Level*) = 0;

    DungeonCrawler* getDungeonCrawler() const;

    void setDungeonCrawler(DungeonCrawler* dungeonCrawler);

    virtual void reset(){;};


protected:
    DungeonCrawler* dungeonCrawler;
};

#endif // ABSTRACTUI_H
