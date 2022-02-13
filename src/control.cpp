#include "control.hpp"
#include <iostream>

void control::getInput(char &userInput, int &xd, int &yd) {
    std::cout << "Enter any of j|i|k|l to move pacman or c to cancel: ";
    std::cin >> userInput;
    switch (userInput) {
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
        xd = 0, yd = 0;
        break;
    }
    std::system("clear");
}