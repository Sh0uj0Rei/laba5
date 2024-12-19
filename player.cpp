#include "player.h"
#include "game.h"
#include "bullet.h"
#include <ncurses.h>
#include <iostream> 

Player::Player(int x, int y, Game* game) : Entities(x, y, 'A'), game(game) {}

void Player::update() {
    int ch = getch();  // Получаем символ с клавиатуры
    if (ch != ERR) {
        
        switch (ch) {
            case KEY_LEFT:
                if (x > 0) x--;  // Движение влево
                break;
            case KEY_RIGHT:
                if (x < 79) x++;  // Движение вправо
                break;
            case ' ':
                shoot();  // Стрельба
                break;
            default:
                break;
        }
    }
}

void Player::shoot() {
    Bullet* bullet = new Bullet(x, y - 1);  // Пуля появляется чуть выше игрока
    game->addEntity(bullet);  // Добавляем пулю в список сущностей игры
}