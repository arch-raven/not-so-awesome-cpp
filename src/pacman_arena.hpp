#pragma once
#include "globals.hpp"

class PacmanArena
{

public:
	static const int HEIGHT = 21, WIDTH = 21;
	char static_board[HEIGHT][WIDTH];
	char board[HEIGHT][WIDTH];
	int pellet_count;

	PacmanArena();
	void readBoard();
	void readStaticBoard();
	void showBoard();
	void showstaticBoard();
	Coords getCharacterPosition(const char icon);
};