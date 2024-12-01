#ifndef GAME_H
#define GAME_H

#include <vector>

// Предварительное объявление класса Player
class Player;
class Entities; // Если у вас есть указатели на Entities

class Game {
private:
    Player* player;
    std::vector<Entities*> entities;
    bool gameOn;

public:
    Game();
    void initializeAliens();
    void input();
    void draw();
    void update();
    void removeInactiveEntities();
    void checkCollisions();
    bool isGameOver() const;
    void addEntity(Entities* entity);
};

#endif // GAME_H