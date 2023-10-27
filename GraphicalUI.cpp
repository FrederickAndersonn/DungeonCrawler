#include "GraphicalUI.h"
#include "DungeonCrawler.h"
#include "mainwindow.h"
#include "mainwindowgame.h"

void GraphicalUI::setLevel(Level *newLevel)
{
    level = newLevel;
}

GraphicalUI::GraphicalUI()
{

}

Level *GraphicalUI::getLevel() const
{
    return level;
}


void GraphicalUI::draw(Level* l){
    level=l;
    mg->printLevel(this);
    mg->hide();
 }

void GraphicalUI::setMg(MainWindowGame *newMg)
{
    mg = newMg;
}

void GraphicalUI::reset(){
    mg->clean();
}
