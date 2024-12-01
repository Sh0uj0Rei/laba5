#include "game.h"
#include "player.h"  // Включаем Player
#include "alien.h"
#include <iostream>
#include <vector>
#include <algorithm> // Для std::remove

Game::Game() {
    player = new Player(40, 18, this);  // Передаем текущий объект игры (this) в Player
    initializeAliens(); 
}

void Game::initializeAliens() {
    // Пример добавления пришельцев
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            entities.push_back(new Alien(10 + j * 5, 2 + i, 'V'));  // Размещение пришельцев
        }
    }
}

void Game::input() {
    // Ввод уже обрабатывается в Player
}

void Game::draw() {
    system("clear"); // Очистка экрана (Linux)

    // Отрисовка игрового поля
    for (int y = 0; y < 20; ++y) {  // Пример для поля 20x80
        for (int x = 0; x < 80; ++x) {
            bool printed = false;

            // Отрисовываем все сущности
            for (auto entity : entities) {
                if (entity->getX() == x && entity->getY() == y) {
                    std::cout << entity->getSymbol();  // Отрисовка символа сущности
                    printed = true;
                    break;
                }
            }

            // Если сущности нет, рисуем игрока
            if (!printed && player->getX() == x && player->getY() == y) {
                std::cout << player->getSymbol(); // Отрисовка игрока
                printed = true;
            }

            // Отрисовываем пули
            if (!printed) {
                for (auto bullet : entities) {
                    if (bullet->getX() == x && bullet->getY() == y) {
                        std::cout << bullet->getSymbol(); // Отрисовка пули
                        printed = true;
                        break;
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Lives: " << player->getLives() << std::endl;
}

void Game::update() {
    player->update();  // Обновляем игрока
    for (auto entity : entities) {
        entity->update();  // Обновляем все сущности (включая пули и пришельцев)
    }
    removeInactiveEntities();  // Удаляем неактивные сущности (например, пули, вышедшие за экран)
    checkCollisions();         // Проверка на столкновения
    if (player->getLives() <= 0) {
        gameOn = false;  // Завершаем игру, если жизни закончились
    }
}

void Game::removeInactiveEntities() {
    // Удаление пуль, которые вышли за экран
    for (auto it = entities.begin(); it != entities.end();) {
        if ((*it)->getY() < 0) {
            it = entities.erase(it);  // Удаление пули
        } else {
            ++it;
        }
    }
}

void Game::checkCollisions() {
    // Пример обработки коллизий (пуль с пришельцами)
    for (auto bullet : entities) {
        for (auto alien : entities) {
            if (bullet->getX() == alien->getX() && bullet->getY() == alien->getY()) {
                // Удаление пули и пришельца
                entities.erase(std::remove(entities.begin(), entities.end(), bullet), entities.end());
                entities.erase(std::remove(entities.begin(), entities.end(), alien), entities.end());
                break;
            }
        }
    }
}

bool Game::isGameOver() const {
    return player->getLives() <= 0; // Игра завершена, если у игрока нет жизней
}

void Game::addEntity(Entities* entity) {
    entities.push_back(entity); // Функция для добавления сущности в список
}
