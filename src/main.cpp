#include "characters.hpp"
#include "control.hpp"
#include "globals.hpp"
#include "pacman_arena.hpp"

using namespace std;

int main() {
    char userInput = 'j';
    int xd, yd;

    PacmanArena arena;
    Pacman pacman(arena);

    while (arena.pellet_count && userInput != 'c' && pacman.alive) {
        arena.showBoard();
        control::getInput(userInput, xd, yd);
        pacman.moveCharacter(xd, yd, arena);
    }
    return 0;
}