#ifndef CHARACTER_H
#define CHARACTER_H

#include "Tile.h"
#include <string>
#include <QPixmap>
class Character {

protected:
    std::string texture;
    Tile* currentTile;
    QPixmap* textureC;

    int strength;
    int stamina;
    int hitpoints;
    int maxHP;
public:
    Character();

    explicit Character(Tile* tile, const std::string& text = "P");

    Character(Tile* tile, int, int);

    virtual ~Character() = default;

    bool isCharacter;

    std::string getTexture();

    Tile* getCurrentTile() const;

    void setCurrentTile(Tile* currentTile);
    QPixmap *getTextureC();
    void setTextureC(QPixmap *newTextureC);

    bool isAlive();

    int getStrength() const;
    int getStamina() const;
    int getHitpoints() const;

    int getMaxHP();

    void hit(int hitpoints);

    void removeCharacter();
    void setTexture(const std::string &newTexture);
    void setHitpoints(int newHitpoints);
};


#endif // CHARACTER_H
