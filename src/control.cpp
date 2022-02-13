#include "control.hpp"
#include <ncurses.h>

void control::greetPlayer() {
    addstr("\n\nUSE KEYPAD to move pacman\n");
    addstr("& key c to exit game\n");
    addstr("\n\nPress any key to Play! \n");
    getch();
    clear();
}

void control::getInput(int &userInput, int &xd, int &yd) {
    userInput = getch();
    switch (userInput) {
    case KEY_LEFT:
        xd = -1, yd = 0;
        break;
    case KEY_UP:
        xd = 0, yd = -1;
        break;
    case KEY_DOWN:
        xd = 0, yd = 1;
        break;
    case KEY_RIGHT:
        xd = 1, yd = 0;
        break;
    case 'c':
        xd = 0, yd = 0;
        break;
    default:
        xd = 0, yd = 0;
        break;
    }
    clear();
}

void control::exitPlayer() {
    addstr("\n\n      GAME OVER      \n\n");
    addstr("\n\nPress any key to Exit! \n");
    getch();
    clear();
}