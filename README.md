# pacman in C++

## TODO

- [ ] Basic SMFL GUI (:construction: WIP branch `sfml`)
- [x] pacman movements
- [x] pacman eat pellets & score count
- [ ] Ghost movements
  - [x] Random Ghost: Take a random turn at intersections
  - [ ] Target some cell
- [x] Collisions Checking
- [x] Invincible Mode
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
# Build
g++ -std=c++17 -o pacman-app src/*.cpp -lncurses
# Run
./pacman-app  
```