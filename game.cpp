#include "game.h"
#include <iostream>
#include <vector>

Game::Game() : gameOn(true) {
    player = new Player(10, 20);
    // Создание пришельцев и добавление в entities
}

void Game::input() {
    // Ввод уже обрабатывается в Player
}

void Game::draw() {
    system("clear"); // Очистка экрана (Linux)
    // Отрисовка всех сущностей
    std::cout << "Lives: " << player->getLives() << std::endl;
    for (auto entity : entities) {
        std::cout << entity->getSymbol() << " at (" << entity->getX() << ", " << entity->getY() << ")" << std::endl;
    }
}

void Game::update() {
    player->update(); // Обновляем игрока
    for (auto entity : entities) {
        entity->update(); // Обновляем все сущности
    }
    // Проверка коллизий и удаление пуль
}

void Game::run() {
    while (gameOn) {
        input();
        draw();
        update();
    }
}
