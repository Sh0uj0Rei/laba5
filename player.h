#ifndef PLAYER_H
#define PLAYER_H

#include "entities.h"
#include "bullet.h"
#include "game.h"

// Предварительное объявление класса Game
class Game;

class Player : public Entities {
public:
    int lives;
    Game* game;  // Указатель на объект игры
    Player(int x, int y, Game* game);
    void update() override;
    void shoot();
    int getLives() const;
    void loseLife();
};

#endif // PLAYER_H