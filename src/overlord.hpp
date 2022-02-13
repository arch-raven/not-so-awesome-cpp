#pragma once
#include "characters.hpp"
#include "globals.hpp"
#include "pacman_arena.hpp"

class Overlord {
  public:
    const int team_size = 4;
    Ghost *team[4];
    Overlord(PacmanArena &arena);
    void work(PacmanArena &arena);
};