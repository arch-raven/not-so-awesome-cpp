#include "globals.hpp"
#include "pacman_arena.hpp"
#include "characters.hpp"
#include <bits/stdc++.h>

using namespace std;

void getInput(char &userInput, int &xd, int &yd)
{
    cout << "Enter any of j|i|k|l to clear screen && move pacman or c to cancel: ";
    cin >> userInput;
    switch (userInput)
    {
    case 'j':
        xd = -1, yd = 0;
        break;
    case 'i':
        xd = 0, yd = -1;
        break;
    case 'k':
        xd = 0, yd = 1;
        break;
    case 'l':
        xd = 1, yd = 0;
        break;
    case 'c':
        xd = 0, yd = 0;
        break;
    default:
        getInput(userInput, xd, yd);
    }
    system("clear");
}

int main()
{
    char userInput = 'j';
    int xd, yd;

    PacmanArena arena;
    Pacman pacman(arena);

    while (arena.pellet_count && userInput != 'c')
    {
        arena.showBoard();
        getInput(userInput, xd, yd);
        pacman.moveCharacter(xd, yd, arena);
    }
    return 0;
}