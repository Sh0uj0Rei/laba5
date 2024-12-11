#include "alien.h"

Alien::Alien(int x, int y, Game* game) : Entities(x, y, 'V'), game(game) {}

void Alien::update() {
    x += direction; // Используем скорость из игры
    if (x <= 0 || x >= 79) {  // Если достигли границы экрана, меняем направление и двигаемся вниз
        direction *= -1;
        y++;
    }
}