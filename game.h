#ifndef GAME_H
#define GAME_H

#include <vector>
#include "entities.h"

class Player;
class Alien;

class Game {
private:
    Player* player;
    std::vector<Entities*> entities;
    bool gameOn;

public:
    Game();
    void addEntity(Entities* entity);
    void input();
    void draw();
    void update();
    bool isGameOver() const;
};

#endif // GAME_H
