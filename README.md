# Unfinished Zombie Game 2 (Name is still being voted on)

A top-down zombie survival game written in C++17 with [SFML 3](https://www.sfml-dev.org/), made as our CS151 final project by **The Cool Guys**.

> **Status:** early development. The player can move around an endless world, shoot a hitscan weapon and reload, and zombies spawn and chase the player. Menus, damage, and real art are still to come.

---

## Building and running

### Requirements
- Windows
- MinGW-w64 `g++` with C++17 support
- SFML 3.1.0
- `make` (e.g. `mingw32-make`)

### Setup
1. Create a `config.mk` file in the project root that points to your SFML install. It's in `.gitignore`, so each person makes their own:
   ```makefile
   SFML_DIR = C:/SFML-3.1.0
   ```
2. Make sure the SFML `.dll` files (`sfml-graphics-3.dll`, `sfml-window-3.dll`, `sfml-system-3.dll`, `sfml-audio-3.dll`) are next to `game.exe`.

### Build
```
make          # builds game.exe
make run      # builds and runs it
```
Run the game from the **project root**, because asset paths like `assets/fonts/...` are relative to the folder the game runs from.

### VS Code IntelliSense
If `#include <SFML/...>` lines show red squiggles, add your SFML include folder to `.vscode/c_cpp_properties.json` (that folder is also in `.gitignore`, so each person sets it up):
```json
"includePath": ["${workspaceFolder}/**", "C:/SFML-3.1.0/include"],
"compilerPath": "C:\\mingw64\\bin\\g++.exe",
"cppStandard": "c++17"
```

---

## Controls

| Input | Action |
|---|---|
| `W` `A` `S` `D` | Move |
| Mouse | Aim |
| Left click | Fire |
| `R` | Reload |

---

## Project structure

```
CS151-Final-Project/
├── include/        Header files (class declarations)
├── src/            Source files (class definitions)
├── assets/
│   ├── art/player/ Survivor sprite sheets (feet, flashlight, handgun, knife, rifle, shotgun)
│   ├── fonts/      Fonts (all SIL Open Font License)
│   ├── music/      Background music
│   └── sfx/        Sound effects
├── makefile
└── config.mk       Your local SFML path (not committed)
```

### Classes

| Class | Files | What it does |
|---|---|---|
| `Game` | `game.h/.cpp` | Owns the window, clock, player, enemies, and world. Runs input, update and render each frame. `main` just creates a `Game` and loops. |
| `Player` | `player.h/.cpp` | WASD movement with acceleration, friction and a max speed (all scaled by delta time). Owns a `Weapon` and a `HealthBar`. |
| `Weapon` | `weapon.h/.cpp` | Hitscan weapon: aims a beam from the player to the mouse, tracks ammo and magazine size, and reloads one round at a time. |
| `Enemy` | `enemy.h/.cpp` | Zombie that accelerates toward the player, with friction, a speed cap, and collision with other enemies. Owns a `HealthBar`. |
| `HealthBar` | `healthbar.h/.cpp` | Bordered bar that follows an entity and shrinks with its health. |
| `Timer` | `timer.h/.cpp` | Small countdown helper (used for the weapon's firing flash). |
| `World` / `Chunk` | `world.h/.cpp`, `chunk.h/.cpp` | Splits the map into 1000×1000 chunks and only loads and draws the ones near the player, so the world can be endless. |
| `Screen` | `screen.h` | Abstract base class for game screens (pure virtual `handleEvent`, `update`, `draw`). |
| `MenuScreen` | `menuscreen.h/.cpp` | Main menu screen, derived from `Screen` (in progress). |

Shared tuning values (window size, player speed, acceleration, friction, enemy stats, chunk size) live in `include/constants.h` under the `Constants` namespace.

---

## Current features
- [x] Frame-rate independent movement (delta time)
- [x] Acceleration, friction and max speed for player and enemies
- [x] Camera that keeps the player centered
- [x] Endless chunk-based world
- [x] Random enemy spawning
- [x] Enemies chase the player and collide with each other
- [x] Hitscan weapon aiming with ammo and reloading
- [x] Health bars
- [x] Removing dead enemies
- [x] Ammo / HUD display
- [x] Hit detection: beam damages the zombie it hits

## To do
- [ ] Player taking damage from zombies
- [ ] Screen system: menu → gameplay → game over (using `Screen`)
- [ ] Move menu and game music into their screens
- [ ] Replace placeholder circles with art
- [ ] Multiple weapons (handgun, rifle, shotgun, knife) / Weapon wheel / Hotbar
- [ ] Sound design

---

## Credits
- **The Cool Guys**: Alex Pulsipher, Alexander Esposito, Joseph, Nick
- Fonts: Oswald, Caveat Brush, Lacquer, Mansalva, Rubik Dirt, Rubik Wet Paint (Google Fonts, SIL Open Font License)
