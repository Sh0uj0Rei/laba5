#include "bullet.h"

Bullet::Bullet(int x, int y) : Entities(x, y, '|') {}

void Bullet::update() {
    y--;  // Пуля движется вверх
}