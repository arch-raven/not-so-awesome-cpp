#include "characters.hpp"
#include "control.hpp"
#include "globals.hpp"
#include "pacman_arena.hpp"
#include <ncurses.h>

using namespace std;

int main() {
    int userInput = 'j';
    int xd = 0, yd = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();

    PacmanArena arena;
    Pacman pacman(arena);

    control::greetPlayer();
    while (arena.pellet_count && userInput != 'c' && pacman.alive) {
        arena.showBoard();
        control::getInput(userInput, xd, yd);
        pacman.moveCharacter(xd, yd, arena);
    }
    control::exitPlayer();
    endwin();
    return 0;
}