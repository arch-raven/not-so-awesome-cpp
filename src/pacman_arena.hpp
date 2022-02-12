#pragma once
#include "globals.hpp"
// class for pacman Arena layout, elements{ ie player, ghosts, walls, boosters, droppables, etc}

class PacmanArena
{

public:
	static const int HEIGHT = 21, WIDTH = 21;
	char static_board[HEIGHT][WIDTH];
	char board[HEIGHT][WIDTH];

	PacmanArena();
	void readBoard();
	void readStaticBoard();
	void showBoard();
	void showstaticBoard();
	Coords getCharacterPosition(const char icon);
};