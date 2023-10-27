#include "AbstractUI.h"
#include "DungeonCrawler.h"

DungeonCrawler* AbstractUI::getDungeonCrawler() const {
    return dungeonCrawler;
}

void AbstractUI::setDungeonCrawler(DungeonCrawler* dCrawler) {
    AbstractUI::dungeonCrawler = dCrawler;
}
