#pragma once
#include "arena.hpp"
#include "globals.hpp"

class Ghost {
  public:
    const char icon = Icons::ghost;
    struct Coords coords;
    unsigned int direction_id = 0;
    Ghost(PacmanArena &arena);
    void moveCharacter(PacmanArena &arena);
};

class Pacman {
  public:
    const char icon = Icons::pacman;
    struct Coords coords;
    struct Coords direction = {0, 0};
    bool alive = true, invincible = false;
    unsigned int score = 0;
    Pacman(PacmanArena &arena);
    void moveCharacter(int xd, int yd, PacmanArena &arena);
    void eatPallete(int x, int y, PacmanArena &arena);
};