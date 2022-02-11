#pragma once
// class for pacman Arena layout, elements{ ie player, ghosts, walls, boosters, droppables, etc}

class PacmanArena{
	
public:
	int HEIGHT=18, WIDTH=32;
	char player_char='@', coins_char='.', bonus_char='$',ghost_char='!', wall_char='#';
	char original_board[18][32];
	char board[18][32];

	PacmanArena();
	void readBoard();
	void showBoard();
	void showOriginalBoard();
};