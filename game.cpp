#include "game.h"
#include "player.h"
#include "alien.h"
#include "bullet.h"
#include <iostream>
#include <ncurses.h>
#include <algorithm>
#include <vector>

Game::Game() {
    player = new Player(40, 18, this);  // Начальная позиция игрока
    addEntity(player);  // Добавляем игрока в сущности игры

    // Добавление пришельцев
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            addEntity(new Alien(10 + j * 5, 2 + i, this));  // Размещение пришельцев
        }
    }

    gameOn = true;
}

void Game::addEntity(Entities* entity) {
    entities.push_back(entity);
}

void Game::input() {
    player->update();  // Обрабатываем действия игрока (движение и стрельба)
}

void Game::draw() {
    clear();  // Очистка экрана с использованием ncurses
    for (auto entity : entities) {
        mvaddch(entity->getY(), entity->getX(), entity->getSymbol());  // Отображаем каждую сущность
    }

    refresh();  // Обновляем экран
}

void Game::update() {
    // Массив для хранения сущностей, которые будут удалены
    std::vector<Entities*> toRemove;

    // Обновляем все сущности
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        (*it)->update();
    }

    // Удаляем пули, которые вышли за экран
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        if ((*it)->getY() < 0) {
            toRemove.push_back(*it);  // Добавляем пулю в список для удаления
        }
    }

    // Проверка на столкновение пуль с пришельцами
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        Bullet* bullet = dynamic_cast<Bullet*>(*it);
        if (bullet) {
            for (auto enemyIt = entities.begin(); enemyIt != entities.end(); ++enemyIt) {
                Alien* alien = dynamic_cast<Alien*>(*enemyIt);
                if (alien && alien->getX() == bullet->getX() && alien->getY() == bullet->getY()) {
                    toRemove.push_back(bullet);  // Добавляем пулю в список для удаления
                    toRemove.push_back(alien);   // Добавляем пришельца в список для удаления
                    break;  // Прерываем цикл, если пуля попала в пришельца
                }
            }
        }
    }

    // Удаление сущностей, которые должны быть удалены
    for (auto entity : toRemove) {
        // Находим и удаляем сущность из основного списка
        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
        delete entity;  // Освобождаем память
    }
}

bool Game::isGameOver() const {
    // Проверка на конец игры: если нет пришельцев, игра закончена
    for (auto entity : entities) {
        if (dynamic_cast<Alien*>(entity)) {
            // Проверяем, достиг ли пришелец нижней границы экрана
            if (entity->getY() >= 18) {
                return true;  // Игра окончена, пришелец дошел до игрока
            }
            return false;  // Есть хотя бы один живой пришелец
        }
    }
    return true;  // Все пришельцы уничтожены
}