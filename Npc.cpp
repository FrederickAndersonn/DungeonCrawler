#include "Npc.h"
#include "attackcontroller.h"

Npc::Npc() : Character(nullptr, "N"), npcController{nullptr} {
    isCharacter=false;
    stamina = 5;
    strength = 10;
    hitpoints = getMaxHP();
    textureC = new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png");
}

AbstractController* Npc::getNpcController() const {
    return npcController;
}

void Npc::setNpcController(AbstractController* npcController) {
    Npc::npcController = npcController;
}
Npc::Npc(Tile* tile, const std::string& text, AbstractController* gController)
    : Character(tile, "N"),
      npcController(gController) {
    isCharacter = false;
    stamina = 5;
    strength = 10;
    hitpoints = getMaxHP();
    textureC = new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png");
}

Npc::Npc(Tile *tile, const string &text, AbstractController *gController, int difficulty):Character(tile, "N"),npcController(gController), difficulty(difficulty)
{
    isCharacter = false;
    stamina = 5;
    strength = 10* difficulty;
    hitpoints = getMaxHP();
    textureC = new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png");
}
Npc::Npc(Tile *tile, const string &text, AttackController *gController, int difficulty):Character(tile, "N"),npcController(gController), difficulty(difficulty)
{
    isCharacter = false;
    stamina = 5;
    strength = 10* difficulty;
    hitpoints = getMaxHP();
    textureC = new QPixmap("/Users/frederickanderson/GoaManjatFinal/textures/zombie/zombie_right.png");
}

