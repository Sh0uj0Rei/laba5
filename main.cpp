#include <iostream>
#include <ncurses.h>
#include "game.h"

int main() {
    initscr(); // Инициализация ncurses
    noecho();  // Не отображать вводимые символы
    cbreak();  // Включить режим немедленного ввода
    keypad(stdscr, TRUE); // Включить поддержку специальных клавиш
    timeout(100); // Устанавливаем задержку для ncurses (например, 100 мс)

    Game game; // Создаем объект игры

    while (!game.isGameOver()) { // Пока игра не завершена
        game.input();  // Обрабатываем ввод
        game.update(); // Обновляем состояние игры
        game.draw();   // Отображаем текущий экран
    }

    // Завершение игры
    clear(); // Очистка экрана перед завершением игры
    mvprintw(10, 35, "Game Over! Press any key to exit..."); // Сообщение о завершении игры
    refresh();
    getch(); // Ожидание нажатия клавиши

    endwin(); // Завершение работы с ncurses
    return 0;
}
