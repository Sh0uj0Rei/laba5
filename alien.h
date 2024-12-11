#ifndef ALIEN_H
#define ALIEN_H

#include "entities.h"
#include "game.h"  // Добавьте это, чтобы использовать класс Game

class Alien : public Entities {
public:
    Alien(int x, int y, Game* game);  // Теперь конструктор принимает объект Game
    void update() override;

private:
    Game* game;  // Указатель на объект Game
};

#endif // ALIEN_H