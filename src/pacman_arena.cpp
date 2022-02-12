#include "pacman_arena.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

PacmanArena::PacmanArena()
{
	this->readBoard();
	this->readStaticBoard();
}

void PacmanArena::readBoard()
{
	std::ifstream file;
	file.open("data.txt");
	for (int i = 0; i < this->HEIGHT; i++)
	{
		for (int j = 0; j < this->WIDTH; j++)
		{
			file >> this->board[i][j];
		}
	}
}

void PacmanArena::readStaticBoard()
{
	for (int i = 0; i < this->HEIGHT; i++)
	{
		for (int j = 0; j < this->WIDTH; j++)
		{
			if (Icons::isIconStatic(this->board[i][j]))
			{
				this->static_board[i][j] = this->board[i][j];
			}
			else
			{
				this->static_board[i][j] = Icons::empty;
			}
		}
	}
}

Coords PacmanArena::getCharacterPosition(const char icon)
{
	for (int i = 0; i < this->HEIGHT; i++)
	{
		for (int j = 0; j < this->WIDTH; j++)
		{
			if (this->board[i][j] == icon)
			{
				std::cout << "Found Icon: " << icon << " at position: " << i << " " << j << std::endl;
				return {j, i};
			}
		}
	}
	std::cout << "Icon: " << icon << " not found" << std::endl;
	return {-1, -1};
}

void PacmanArena::showBoard()
{
	for (int i = 0; i < this->HEIGHT; i++)
	{
		for (int j = 0; j < this->WIDTH; j++)
		{
			std::cout << this->board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void PacmanArena::showstaticBoard()
{
	std::cout << "---------ORIGINAL BOARD---------\n";
	for (int i = 0; i < this->HEIGHT; i++)
	{
		for (int j = 0; j < this->WIDTH; j++)
		{
			std::cout << this->static_board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}