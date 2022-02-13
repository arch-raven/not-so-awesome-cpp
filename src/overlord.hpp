#pragma once
#include "arena.hpp"
#include "characters.hpp"
#include "globals.hpp"

class Overlord {
  public:
    const int team_size = 4;
    Ghost *team[4];
    Overlord(PacmanArena &arena);
    void work(PacmanArena &arena);
};