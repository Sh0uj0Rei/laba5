#include "alien.h"

Alien::Alien(int x, int y) : Entities(x, y, 'V') {}

void Alien::update() {
    x += direction; // Двигаемся вправо или влево
    if (x <= 0 || x >= 79) {  // Если достигли границы экрана, меняем направление и двигаемся вниз
        direction *= -1;
        y++;
    }
}
