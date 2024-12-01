
#include <vector>
#include "entities.h"
#include "player.h"
#include "alien.h"
#include "bullet.h"

class Game {
private:
    Player* player;
    std::vector<Entities*> entities;
    bool gameOn;

public:
    Game();
    void input();
    void draw();
    void update();
    void run();
};