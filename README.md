# pacman in C++

## TODO

- [ ] Basic SMFL GUI
- [x] pacman movements
- [x] pacman eat pellets & score count
- [ ] Ghost movements
  - [x] Dumb Ghost: Always Take Right, always!
  - [ ] Target some cell
- [ ] Collisions/Collectibles Checking
- [ ] Advanced Ghost Behaviour Modes [youtube](https://youtu.be/ataGotQ7ir8) | [blog](https://gameinternals.com/understanding-pac-man-ghost-behavior)
    - Chase
    - Scatter
    - Eaten
    - Frightened
- [ ] Individual Ghost Behaviours


## Dependencies

1. C++17
1. SFML
   1. Arch: `pacman -S sfml`
   2. Debian: `apt-get update && apt-get install libsfml-dev`

## Build & Run

```bash
g++ -std=c++17 -o pacman-app src/*.cpp -lncurses
./pacman-app  
```