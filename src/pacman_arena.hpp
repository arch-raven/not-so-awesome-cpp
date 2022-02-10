// class for pacman Arena layout, elements{ ie player, ghosts, walls, boosters, droppables, etc}
#pragma once
#include <iostream>
#include <string>

struct Coords{
	int x;
	int y;
};

class PacmanArena{

private:
	int HEIGHT=18, WIDTH=32;
	char player_char='@', coins_char='$', ghost_char='!';

public:
	char original_board[18][32];
	char board[18][32];

	struct Coords player={16,8};

	PacmanArena(int a_x, int a_y);
	void readBoard();
	void showBoard();
	void showOriginalBoard();
	void movePlayer(int xd, int yd);

};

PacmanArena::PacmanArena(int a_x=16, int a_y=8){
	player={a_x,a_y};
	readBoard();
	board[player.y][player.x]=player_char;
}

void PacmanArena::readBoard(){
	std::ifstream file;
	file.open("data.txt");
	char temp;
	for (int i=0;i<HEIGHT;i++){
		for (int j=0;j<WIDTH;j++){
			file >> temp; 
			original_board[i][j]=(temp=='#'?'#':'-');
		}
	}
	memcpy(board, original_board, HEIGHT*WIDTH*sizeof(char));
}

// move to Characters/pacman class
void PacmanArena::movePlayer(int xd, int yd){
	board[player.y][player.x] = original_board[player.y][player.x];
	player.x+=xd;
	player.y+=yd;
	board[player.y][player.x] = player_char;
}


void PacmanArena::showBoard(){
	for(int i = 0; i < HEIGHT; i++) {
		for (int j=0;j<WIDTH;j++){
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void PacmanArena::showOriginalBoard(){
	std::cout << "---------ORIGINAL BOARD---------\n";
	for(int i = 0; i < HEIGHT; i++) {
		for (int j=0;j<WIDTH;j++){
			std::cout << original_board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}