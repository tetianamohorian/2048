# 2048
### 1.  Description

* Purpose:
    - The C code described implements a text-based version of the popular 2048 game. 
    - It provides a user interface using the ncurses library for terminal control, enabling you to play the game within your command prompt or terminal window.


### 2. How to translate and run the program ?

- Install Libraries: Ensure you have the curses library installed. 
It might come pre-installed on your system or require separate installation.


- Compile the program
    ````c
    gcc program.c -lncurses -o program
    ````

- Run the program using the command: 
    ````c
    ./program
    ````


### 3. How the program is programmed?

* Key Functions:

    - Initialization (pStart()): Initializes ncurses, enables colors, disables keypress echoing, and sets raw mode for unprocessed keystrokes.
    - Border Drawing (pDrawBorder()): Creates the game board's visual border using ASCII characters and color attributes.
    - Tile Placement (pTilePlacement(int pTile[16])): Initializes the game board by filling it with zeros and randomly placing two starting tiles (2 or 4).
    - Tile Drawing (pDrawTile(int pNumber, int pTileNumber)): Handles drawing individual tiles on the board, considering their position and value, and using color attributes for visual distinction.
    - Information Display (pPrintInfo(int pResult)): Displays different messages based on the game state: instructions, win message, or lose message. It also provides options to restart (r) or quit (q).
    - Key Input Handling (pGetKey()): Reads keypresses from the user, interpreting escape sequences for arrow keys and converting them to movement directions (Up, Down, Right, Left).
    - Tile Movement (pMoveTile(int pTile[16], char direction)): Implements the core game logic. It iterates through the tile array in the specified direction, shifting tiles left and merging adjacent tiles with the same value. It calculates the score gained from these merges.
    - Score Display (pPrintStatus(int k)): Prints the current score in the top right corner of the screen.
    - Game Over Check (pCheckEnd(int pTile[16])): Determines if the game is over. It creates a copy of the current board state and simulates moves in all directions. If any simulated move would change the board state, it means the game is not over (valid moves still exist). Otherwise, the game is considered lost.
    - Main Function (main()):
        * Initializes game variables (score, tile array, backup tile array, move direction, flags, etc.).
        * Enters a game loop that continues until the user quits (q) or loses.
        * Resets the score and fills the tile array with zeros.
        * Places two starting tiles randomly.
        * Enters a sub-loop that continues until a valid move is made or the user exits.
        * Draws the game board (border, tiles, score).
        * Gets a keypress from the user.
        * Checks for quit (q) and restart (r) keypresses.
        * If a valid movement key is pressed, calls pMoveTile to move tiles and update the score.
        * Checks if the move resulted in a change in the tile state (flag_change). If true (meaning tiles merged or shifted), redraws the board and resets the flag.
        * Checks for the win condition (reaching 2048 tile) using the pTile array.
        * Checks for the game over condition using pCheckEnd.
    - Based on the win or lose flag, displays the corresponding message or continues looping.


### 4. Links to source code and websites that were used in the solution

-   [Geek for Geeks](https://www.geeksforgeeks.org/2048-game-in-c/)
-   [ncurses](https://man7.org/linux/man-pages/man3/ncurses.3x.html)
