#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include <vector>
#include "AbstractUI.h"
#include "Level.h"
#include "QtWidgets/qlabel.h"


class MainWindowGame;


class GraphicalUI : public AbstractUI {
private:
    Level*level;
    MainWindowGame* mg;
public:
    GraphicalUI();
    void draw(Level*);
    Level *getLevel() const;
    void setMg(MainWindowGame *newMg);
    vector<QPixmap*> floors{
        new QPixmap("../GoaManjatFinal/textures/floor/floor1.png"),
        new QPixmap("../GoaManjatFinal/textures/floor/floor2.png"),
        new QPixmap("../GoaManjatFinal/textures/floor/floor3.png"),
        new QPixmap("../GoaManjatFinal/textures/floor/floor4.png"),
    };
    vector<QPixmap*>doors{
        new QPixmap("../GoaManjatFinal/textures/doors/door1.png"),
        new QPixmap("../GoaManjatFinal/textures/doors/door2.png"),
    };
    vector<QPixmap*>wall{
        new QPixmap("../GoaManjatFinal/textures/wall/wall1.png")
    };
    vector<QPixmap*>portals{
        new QPixmap("../GoaManjatFinal/textures/portal/portal1.png"),
        new QPixmap("../GoaManjatFinal/textures/portal/portal2.png"),
    };
    vector<QPixmap*>pit{
        new QPixmap("../GoaManjatFinal/textures/pit.png")
    };
    vector<QPixmap*>ramp{
        new QPixmap("../GoaManjatFinal/textures/ramp.png")
    };
    vector<QPixmap*>switches{
        new QPixmap("../GoaManjatFinal/textures/switch.png")
    };
    void resizeCharacter(QLabel* obj, QLabel* character);

    void reset()override;


    void setLevel(Level *newLevel);
};
#endif // GRAPHICALUI_H
