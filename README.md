# Sokoban Game

This project is an implementation of the classic board game Sokoban, developed as part of the Basics of Programming course in the Data Engineering program. The objective of the game is to move crates to their designated positions on the board by navigating a player character.

## Game Description

The game board consists of square fields, which can be categorized as follows:

- Empty: Free fields where the player and crates can move.
- Player: The position occupied by the player character.
- Crate: Crates that need to be moved to their destination.
- Destination: Target positions where the crates should be placed.
- Wall: Obstacles that cannot be passed through.

The game is played by moving the player character one field at a time using the arrow keys. The player can push a single crate at a time, but cannot pull them or move them sideways. The goal is to strategically move the crates to their respective destinations, ultimately solving the puzzle.

For a more detailed description of the Sokoban game, please refer to [Wikipedia](https://en.wikipedia.org/wiki/Sokoban).

## Programming Environment

This project utilizes the SDL2 (2.0.3) library for graphics and user input. The provided basic program includes features for time calculation, drawing bitmap graphics, rendering shapes, and displaying text. The SDL2 library is already included in the project, so there is no need to download the sources separately.

To compile the project, ensure that the following files and directories are present in the same directory as `main.cpp`:

- Bitmaps: Required pictures, such as `cs8x8.bmp` and `eti.bmp`.
- Library File: `libSDL2.a` (or `libSDL2-64.a` for 64-bit systems) for linking SDL2.
- SDL Directory: Contains necessary SDL2 files.

For Linux systems, the project can be compiled using the provided compilation script:

```bash
./comp
```

For Windows systems, it can be compiled using MS Visual C++ Studio with the version available in the laboratory.

## Specifications

The project consists of basic and advanced functionality

### Basic Functionality
1. Display the game board in an aesthetically pleasing and user-friendly manner.
2. Show the elapsed time during gameplay. The timer resets when a new board is loaded.
3. Move the player character using arrow keys in free fields without breaking walls. The movement should be immediate and responsive to events. The player cannot enter walls or move crates.

### Advanced Functionality

1. Push crates by moving into them, provided the field behind them is free. The player cannot move two crates simultaneously
2. Add animated transitions between fields 
3. Load the game board from a file
4. Implement a menu system that includes the following options:
   - Load ready-made boards on different levels. The boards should be listed in the menu, and their filenames should not be directly embedded in the program code. You can use an additional configuration file (txt) to list available boards.
   - Allow users to add their own boards by providing a file name.
   - Enable playing multiple games consecutively within a single program launch.
5. Detect the successful completion of each level and display a message indicating the achievement 
6. Store and display a list of best results for each level, including the number of moves and time to complete.

 The player can append their result to the list after solving the board. The best results' list should be persisted across program launches, stored in a file, and sorted by time and number of moves
![option screen](https://github.com/Osama-Nasr/Sokoban_osama/assets/86621076/d4dbc97f-dee0-4ec4-bdf8-f5c5f298361c)
![starting page](https://github.com/Osama-Nasr/Sokoban_osama/assets/86621076/b88e3462-fe36-4ba7-8af7-e89d03385ec4)
![win screen](https://github.com/Osama-Nasr/Sokoban_osama/assets/86621076/662b36bb-9785-4d16-98fe-6bac796d0ff0)
![game status screen](https://github.com/Osama-Nasr/Sokoban_osama/assets/86621076/0784f837-1afc-4dba-94f3-d855d3c0b1b9)
