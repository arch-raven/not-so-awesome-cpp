#pragma once
#include "globals.hpp"
#include "pacman_arena.hpp"

class Ghost {
  public:
    char icon = Icons::ghost;
    struct Coords coords;
    Ghost(PacmanArena &arena);
    void moveCharacter(int xd, int yd, PacmanArena &arena);
};

class Pacman {
  public:
    char icon = Icons::pacman;
    struct Coords coords;
    struct Coords direction;
    bool alive = true, invincible = false;
    Pacman(PacmanArena &arena);
    void moveCharacter(int xd, int yd, PacmanArena &arena);
};