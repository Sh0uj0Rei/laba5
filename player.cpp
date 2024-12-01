#include "player.h"
#include "bullet.h"
#include <iostream>
#include <ncurses.h> // Подключаем ncurses

Player::Player(int x, int y) : Entities(x, y, '^', 1), lives(3) {}

void Player::update() {
    int ch;
    if ((ch = getch()) != ERR) { // Проверяем, была ли нажата клавиша
        switch (ch) {
            case 'a': // Влево
                if (x > 0) x--; // Движение влево, если не на краю
                break;
            case 'd': // Вправо
                if (x < 79) x++; // Движение вправо, если не на краю
                break;
            case ' ': // Стрельба
                shoot();
                break;
        }
    }
}

void Player::shoot() {
    Bullet* bullet = new Bullet(x, y - 1); // Создаем пулю над игроком
    // Добавьте пулю в список сущностей игры (например, в Game)
}

int Player::getLives() const { return lives; }
void Player::loseLife() { lives--; }
