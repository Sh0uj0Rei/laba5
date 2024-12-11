#ifndef PLAYER_H
#define PLAYER_H

#include "entities.h"
#include "game.h"

class Player : public Entities {
public:
    Game* game;
    Player(int x, int y, Game* game);
    void update() override;
    void shoot();
};

#endif // PLAYER_H