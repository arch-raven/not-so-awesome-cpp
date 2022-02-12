#pragma once
#include "globals.hpp"
#include "pacman_arena.hpp"

class Character
{
public:
    char icon = Icons::rand;
    struct Coords coords;
    Character(PacmanArena &arena);
    void moveCharacter(int xd, int yd, PacmanArena &arena);
};

class Ghost : public Character
{
public:
    Ghost(PacmanArena &arena) : Character(arena)
    {
        this->icon = Icons::ghost;
        this->coords = arena.getCharacterPosition(this->icon);
    }
};

class Pacman : public Character
{
public:
    Pacman(PacmanArena &arena) : Character(arena)
    {
        this->icon = Icons::pacman;
        this->coords = arena.getCharacterPosition(this->icon);
    }
};