#pragma once
#include "globals.hpp"
#include "pacman_arena.hpp"
// classes for diff characters:= Pacman & Ghosts

class Character
{

public:
    char icon = Icons::pacman;
    struct Coords coords;
    Character(PacmanArena &arena);
    void moveCharacter(int xd, int yd, PacmanArena &arena);
};
