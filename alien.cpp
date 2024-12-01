#include "alien.h"

Alien::Alien(int x, int y, char type) : Entities(x, y, type, 1) {}

void Alien::update() {
    x += direction; // Двигаемся в текущем направлении

    // Проверка на столкновение со стенами
    if (x <= 0 || x >= 79) {
        direction *= -1; // Изменяем направление
        y++; // Опускаемся на одну строку вниз
    }
}
