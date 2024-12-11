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
    int score;            // Счет
    int lives;            // Жизни игрока
    int alienSpeed;       // Скорость движения пришельцев

public:
    Game();
    void addEntity(Entities* entity);
    void input();
    void draw();
    void update();
    bool isGameOver() const;
    void decreaseLives();  // Метод для уменьшения жизней
    void increaseScore();   // Метод для увеличения счета
    void changeAlienSpeed(int speed);  // Метод для изменения скорости пришельцев
    int getScore() const;   // Получить текущий счет
    int getLives() const;   // Получить текущие жизни
};

#endif // GAME_H