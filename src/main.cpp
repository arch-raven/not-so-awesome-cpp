#include "arena.hpp"
#include "characters.hpp"
#include "control.hpp"
#include "globals.hpp"
#include <ncurses.h>

int main() {
    int userInput = 'j';
    int xd = 0, yd = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();

    PacmanArena arena;
    Pacman pacman(arena);
    Overlord overlord(arena);

    control::greetPlayer();
    while (arena.pellet_count && userInput != 'c' && pacman.alive) {
        arena.showBoard();
        control::getInput(userInput, xd, yd);
        pacman.moveCharacter(xd, yd, arena);
        overlord.checkForHeadonCollision(arena, pacman);
        overlord.work(arena, pacman);
    }
    control::exitPlayer(pacman.score);
    endwin();
    return 0;
}