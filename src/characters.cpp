#include "characters.hpp"
#include "globals.hpp"
// #include <ncurses.h>

Pacman::Pacman(PacmanArena &arena) {
    this->coords = arena.getCharacterInitialPosition(this->icon);
}

void Pacman::moveCharacter(int xd, int yd, PacmanArena &arena) {
    // Continue in previous direction if no new input
    // Else update direction of where pacman is headed
    if (xd == 0 && yd == 0) {
        xd = this->direction.x, yd = this->direction.y;
    } else {
        this->direction = {xd, yd};
    }

    int x = this->coords.x, y = this->coords.y;
    xd = (xd + x + arena.WIDTH) % arena.WIDTH; // teleportation magic
    yd = yd + y; // cant teleport vertically since no vertcal portals

    // hit a wall, can't move in this direction
    if (arena.board[yd][xd] == Icons::wall) {
        return;
    }

    arena.board[y][x] = arena.static_board[y][x];
    arena.board[yd][xd] = this->icon;
    this->coords = {xd, yd};
    this->eatPallete(xd, yd, arena);
}

void Pacman::eatPallete(int x, int y, PacmanArena &arena) {
    // eats pellete if present
    switch (arena.static_board[y][x]) {
    case Icons::pellet:
        this->score += Constants::pallete_points;
        arena.static_board[y][x] = Icons::empty;
        arena.pellet_count--;
        return;
    case Icons::power_pellet:
        this->score += Constants::power_pallete_points;
        arena.static_board[y][x] = Icons::empty;
        arena.pellet_count--;
        return;
    default:
        return;
    }
}

Ghost::Ghost(PacmanArena &arena) {
    this->coords = arena.getCharacterInitialPosition(this->icon);
}

void Ghost::moveCharacter(PacmanArena &arena) {
    // printw("[DEBUG] Current direction: %d\n", this->direction_id);
    int x = this->coords.x, y = this->coords.y;
    for (int i = 0; i > -4; i--) {
        auto direction =
            Constants::directions[(this->direction_id + i + 1) % 4];
        if (arena.board[y + direction.y][x + direction.x] != Icons::wall) {
            arena.board[y][x] = arena.static_board[y][x];
            y += direction.y;
            x += direction.x;
            arena.board[y][x] = this->icon;
            this->coords = {x, y};
            this->direction_id = (this->direction_id + i + 1) % 4;
            // printw("[DEBUG] Decision direction: %d\n", this->direction_id);
            return;
        }
    }
}