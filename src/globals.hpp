#pragma once

struct Coords {
    int x; // horizontal left to right
    int y; // vertical depth ie up to down

    bool operator==(const Coords &i_coord) {
        return this->x == i_coord.x && this->y == i_coord.y;
    }
};

class Icons {
  public:
    static const char pacman = '@';
    static const char ghost = '!';
    static const char wall = '#';
    static const char pellet = '.';
    static const char power_pellet = '$';
    static const char empty = '-';
    static const char rand = 'G';

    static bool isIconStatic(const char icon) {
        switch (icon) {
        case Icons::pacman:
            return false;
        case Icons::ghost:
            return false;
        default:
            return true;
        }
    }
};

namespace Constants {
    const unsigned int pallete_points = 20;
    const unsigned int power_pallete_points = 200;
} // namespace Constants