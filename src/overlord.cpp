#include "overlord.hpp"

Overlord::Overlord(PacmanArena &arena) {
    for (int i = 0; i < this->team_size; i++) {
        this->team[i] = new Ghost(arena);
    }
}

void Overlord::work(PacmanArena &arena) {
    for (int i = 0; i < this->team_size; i++) {
        this->team[i]->moveCharacter(arena);
    }
}
