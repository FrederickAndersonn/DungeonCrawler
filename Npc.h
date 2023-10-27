#ifndef NPC_H
#define NPC_H
#include "AbstractController.h"
#include "Character.h"
class GuardController;
class AttackController;

class Npc : public Character {

private:
    AbstractController* npcController;
    int difficulty;

public:
    AbstractController* getNpcController() const;

    void setNpcController(AbstractController* npcController);
    Npc(Tile* tile, const std::string& text, AbstractController* gController);
    Npc(Tile* tile, const std::string& text, AbstractController* gController,int);
    Npc(Tile *tile, const string &text, AttackController *gController, int difficulty);
    Npc();
};


#endif // NPC_H
