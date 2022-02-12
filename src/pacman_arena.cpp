#include "pacman_arena.hpp"
#include <fstream>
#include <iostream>
#include <cstring>
// class for pacman Arena layout, elements{ ie player, ghosts, walls, boosters, droppables, etc}

PacmanArena::PacmanArena(){
	this->readBoard();
}

void PacmanArena::readBoard(){
	std::ifstream file;
	file.open("data.txt");
	for (int i=0;i<this->HEIGHT;i++){
		for (int j=0;j<this->WIDTH;j++){
			file >> this->original_board[i][j]; 
		}
	}
	std::memcpy(this->board, this->original_board, this->HEIGHT*this->WIDTH*sizeof(char));
}


void PacmanArena::showBoard(){
	for(int i = 0; i < this->HEIGHT; i++) {
		for (int j=0;j<this->WIDTH;j++){
			std::cout << this->board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void PacmanArena::showOriginalBoard(){
	std::cout << "---------ORIGINAL BOARD---------\n";
	for(int i = 0; i < this->HEIGHT; i++) {
		for (int j=0;j<this->WIDTH;j++){
			std::cout << this->original_board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}