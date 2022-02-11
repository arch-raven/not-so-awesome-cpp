#include <iostream>
#include "characters.hpp"

bool Coords::operator==(const Coords& i_coord){
	return this->x==i_coord.x && this->y==i_coord.y;
}

Character::Character(PacmanArena& arena){
    arena.board[this->coords.y][this->coords.x] = this->icon;
}

void Character::moveCharacter(int xd, int yd, PacmanArena& arena){
    if (xd==0 && yd==0){
        return;
    }
    auto x=this->coords.x, y=this->coords.y;
    // std::cout << "wall_car: " << arena.wall_char << std::endl;
    // std::cout << "y+yd: " << y+yd << " | " << arena.board[y+yd][x] << std::endl;
    // std::cout << "x+xd: " << x+xd << " | " << arena.board[y][x+xd] << std::endl;

	if (
        (xd==0 && arena.board[y+yd][x]==arena.wall_char) || 
        (yd==0 && arena.board[y][x+xd]==arena.wall_char)
    ){
        return; //hit a wall, can't move in this direction
    }
    // std::cout << "Reached moveCharacter C2" << std::endl;
    arena.board[y][x] = arena.original_board[y][x];
	this->coords.y+=yd;
    this->coords.x+=xd;
	arena.board[this->coords.y][this->coords.x] = this->icon;
}