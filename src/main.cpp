#include <bits/stdc++.h>
#include "pacman_arena.hpp"
using namespace std;


int main(){
    PacmanArena arena;

    arena.showOriginalBoard();
    
    for (int i=0;i<4;i++){
        arena.movePlayer(3,0);
	    arena.showBoard();
    }
    return 0;
}