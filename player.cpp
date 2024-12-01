#include "player.h"
#include "bullet.h"
#include <iostream>
#include <ncurses.h> // Подключаем ncurses
#include "game.h"
#include "entities.h"

Player::Player(int x, int y, Game* game) : Entities(x, y), lives(3), game(game) {
    // Инициализация
}

void Player::update() {
    int ch;
    if ((ch = getch()) != ERR) { // Проверяем, была ли нажата клавиша
        switch (ch) {
            case KEY_LEFT: // Стрелка влево
                if (x > 0) x--; // Движение влево, если не на краю
                break;
            case KEY_RIGHT: // Стрелка вправо
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
    game->addEntity(bullet);  // Добавляем пулю в игру через объект game
}

int Player::getLives() const { return lives; }
void Player::loseLife() { lives--; }