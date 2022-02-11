#pragma once
#include "pacman_arena.hpp"
// classes for diff characters:= Pacman & Ghosts

struct Coords{
	int x; //horizontal left to right
	int y; //vertical depth ie up to down

	bool operator==(const Coords& i_coord);
};

class Character{

public:
    char icon='@';
    struct Coords coords={16,8};
    Character(PacmanArena& arena);
    void moveCharacter(int xd, int yd, PacmanArena& arena);
};
