#include "bullet.h"

Bullet::Bullet(int x, int y) : Entities(x, y, '|', 1) {}

void Bullet::update() {
    y--; // Двигаемся вверх
    if (y < 0) {
        // Удалить пулю, если она вышла за пределы экрана
    }
}