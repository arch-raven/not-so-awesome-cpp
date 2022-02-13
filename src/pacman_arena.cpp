#include "pacman_arena.hpp"
#include <fstream>
#include <ncurses.h>

PacmanArena::PacmanArena() {
    this->readBoard();
    this->readStaticBoard();
    this->pellet_count = 0;
    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            if (this->board[i][j] == Icons::pellet ||
                this->board[i][j] == Icons::power_pellet) {
                this->pellet_count++;
            }
        }
    }
    printw("[DEBUG] %d  Pellets found\n", this->pellet_count);
}

void PacmanArena::readBoard() {
    std::ifstream file;
    file.open("data.txt");
    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            file >> this->board[i][j];
        }
    }
}

void PacmanArena::readStaticBoard() {
    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            this->static_board[i][j] = this->board[i][j];
        }
    }
}

Coords PacmanArena::getCharacterInitialPosition(const char icon) {
    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            if (this->static_board[i][j] == icon) {
                this->static_board[i][j] = Icons::empty;
                printw("[DEBUG] Found Icon: %c  at position: (%d, %d)\n", icon,
                       i, j);
                return {j, i};
            }
        }
    }
    printw("[DEBUG:FATAL] Icon Not Found: %c\n", icon);
    return {-1, -1};
}

void PacmanArena::showBoard() {
    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            addch(this->board[i][j] == Icons::empty ? ' ' : this->board[i][j]);
            addch(' ');
        }
        addch('\n');
    }
    refresh();
}

void PacmanArena::showstaticBoard() {
    addstr("---------ORIGINAL BOARD---------\n");
    for (int i = 0; i < this->HEIGHT; i++) {
        for (int j = 0; j < this->WIDTH; j++) {
            addch(this->static_board[i][j]);
            addch(' ');
        }
        addch('\n');
    }
}