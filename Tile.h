#ifndef TILE_H
#define TILE_H
#include <string>
#include <QPixmap>
class Character;
using namespace std;

class Tile
{
protected:
    string texture;
    Character* character;
    QPixmap* textureGUI;
    int row;
    int col;
public:
    Tile();
    Tile(const string, int, int ,Character*);
    virtual ~Tile()= default;
    string getTexture() const;
    int getRow() const;
    int getCol() const;
    void setCharacter(Character*);
    Character* getCharacter();
    bool moveTo(Tile*, Character*);
    bool hasCharacter();
    virtual Tile* onEnter(Tile*, Character*)=0;
    virtual Tile* onLeave(Tile*, Character*)=0;
    void setTexture(string);
    virtual QPixmap* getTextureGUI()=0;
    virtual void setTextureGUI(QPixmap*)=0;
    bool initFight(Character *attacker, Character *defender);
    void removeCharacter();
    std::vector<Tile*> neighbours;
    std::vector<Tile*> getNeighbours(){return neighbours;};

};

#endif // TILE_H
