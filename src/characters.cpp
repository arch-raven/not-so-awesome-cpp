#include "globals.hpp"
#include "characters.hpp"
#include <iostream>

Character::Character(PacmanArena &arena)
{
    Coords pos = arena.getCharacterPosition(this->icon);
    this->coords.x = pos.x;
    this->coords.y = pos.y;
}

void Character::moveCharacter(int xd, int yd, PacmanArena &arena)
{
    if (xd == 0 && yd == 0)
    {
        return;
    }
    auto x = this->coords.x, y = this->coords.y;

    if (
        (xd == 0 && arena.board[y + yd][x] == Icons::wall) ||
        (yd == 0 && arena.board[y][x + xd] == Icons::wall))
    {
        return; // hit a wall, can't move in this direction
    }

    arena.board[y][x] = arena.static_board[y][x];
    this->coords.y += yd;
    this->coords.x += xd;
    arena.board[this->coords.y][this->coords.x] = this->icon;
}