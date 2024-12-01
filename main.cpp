#include <iostream>
#include <vector>
#include <ncurses.h>
#include "player.h"
#include "alien.h"
#include "bullet.h"

int main() {
    initscr(); // Инициализация ncurses
    noecho(); // Не отображать вводимые символы
    cbreak(); // Включить режим немедленного ввода
    keypad(stdscr, TRUE); // Включить поддержку специальных клавиш

    Player player(40, 20);
    while (true) {
        player.update();
        // Другие действия игры...
    }

    endwin(); // Завершение работы с ncurses
    return 0;
}
