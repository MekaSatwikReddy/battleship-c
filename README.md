# Battleship Game in C

A two-player terminal-based implementation of the classic Battleship game written in C.
Players place ships on a 10×10 grid and take turns attempting to locate and sink the opponent’s ships.

---

## Features

* Interactive **ship placement system**
* **10×10 grid board** with coordinate-based targeting
* **Turn-based gameplay**
* **Hit / miss detection**
* **Persistent match history**
* **Player statistics tracking**
* Menu-driven terminal interface

---

## Game Overview

Each player places ships on their board and then takes turns attacking coordinates on the opponent's board.

The game continues until one player successfully sinks all of the opponent’s ships.

Ships used in the game:
* Length 6
* Length 5
* Length 4
* Length 3
* Length 2

---

## File Structure

```
battleship-c
│
├── main.c           # Program entry point and menu system
├── board_logic.c    # Board initialization, ship placement and hit detection
├── board_logic.h
├── game_loop.c      # Core game loop and board rendering
├── game_loop.h
├── history.c        # Match history and player statistics management
├── history.h
├── Makefile         # Build instructions
└── README.md
```

---

## Compilation

### Using Makefile

```bash
make
```

### Manual Compilation

```bash
gcc main.c board_logic.c game_loop.c history.c -o battleship
```

---

## Running the Program

After compiling:

```bash
./battleship
```

---

## Data Persistence

The game stores match information using text files:

* `text.txt` → stores match history (winner, loser, score)
* `players.txt` → stores player statistics

These files are generated automatically when the game runs.

---

## Concepts Used

This project demonstrates several core C programming concepts:

* Modular programming with multiple source files
* Header file organization
* Arrays and multi-dimensional arrays
* Structs
* File I/O
* Input validation
* Game loop design

---

## Contributors

This project was developed as a **group project**.

* Meka Satwik Reddy
* Challa Karthik Reddy
* P Nanda Koushik

---

## Future Improvements

Possible enhancements include:

* Single-player mode with AI opponent
* Random ship placement
* Improved UI
* Graphical interface
* Network multiplayer support

---

## License

This project is intended for educational purposes.
