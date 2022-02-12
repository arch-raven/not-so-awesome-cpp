#include "globals.hpp"
#include "characters.hpp"
#include <iostream>

Pacman::Pacman(PacmanArena &arena)
{
    this->coords = arena.getCharacterPosition(this->icon);
}

void Pacman::moveCharacter(int xd, int yd, PacmanArena &arena)
{
    auto x = this->coords.x, y = this->coords.y;
    xd = (xd + x + arena.WIDTH) % arena.WIDTH; // teleportation magic
    yd = yd + y;                               // cant teleport vertically since no vertcal portals

    if (
        (xd == x && yd == y) ||               // No change
        (arena.board[yd][xd] == Icons::wall)) // hit a wall, can't move in this direction
    {
        return;
    }

    arena.board[y][x] = arena.static_board[y][x];
    arena.board[yd][xd] = this->icon;
    this->coords = {xd, yd};
}