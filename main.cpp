#include <iostream>
#include <vector>
#include <ncurses.h>
#include "game.h"

int main() {
    initscr(); // Инициализация ncurses
    noecho(); // Не отображать вводимые символы
    cbreak(); // Включить режим немедленного ввода
    keypad(stdscr, TRUE); // Включить поддержку специальных клавиш
    timeout(100); // Устанавливаем задержку для ncurses (например, 100 мс)

    Game game; // Создаем объект игры

    while (true) {
        game.input(); // Обрабатываем ввод
        game.draw();  // Отображаем текущий экран
        game.update(); // Обновляем состояние игры

        // Проверяем завершение игры (например, если у игрока закончились жизни)
        if (game.isGameOver()) {
            break; // Прерываем цикл, если игра завершена
        }
    }

    endwin(); // Завершение работы с ncurses
    return 0;
}