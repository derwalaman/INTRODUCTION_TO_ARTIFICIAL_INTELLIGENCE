# Tic-Tac-Toe: AI vs User (Minimax Algorithm)

This project implements a two-player Tic-Tac-Toe game where the user plays as 'X' and the computer plays as 'O'. The computer uses the **Minimax algorithm** to make optimal decisions, ensuring that the AI always plays perfectly.

## Features

- **Two-player Game**: One player (the user) plays as 'X' and the other (the computer) plays as 'O'.
- **Minimax Algorithm**: The AI uses the Minimax algorithm to decide its best possible move, ensuring an optimal game.
- **Game Flow**: The game alternates turns between the user and the computer, and ends when a player wins, or a draw occurs.
- **Board Representation**: The Tic-Tac-Toe board is represented as a 3x3 grid.
- **User Input**: The user provides row and column values to place their move.
- **Invalid Move Handling**: The game checks for invalid moves (like selecting an already occupied cell).
- **Game Outcome**: Displays if the user wins, the computer wins, or if it's a draw.

## Game Instructions

1. The game starts with an empty 3x3 grid.
2. The user plays as 'X' and enters a row and column (0-2) to place their move.
3. The computer (AI) plays as 'O' and calculates the best move using the **Minimax algorithm**.
4. The game continues until either the user or the computer wins, or the game results in a draw.

## How to Run

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/tic-tac-toe-minimax.git
2. Navigate to the project folder:

    ```bash
    cd tic-tac-toe-minimax
    ```
3. Compile the C++ code:
    ```bash
    g++ -o tic_tac_toe main.cpp
    ```

4. Run the program:
    ```bash
    ./tic_tac_toe
    ```

## Board Representation
- The board is represented as a 2D array:
    ```bash 
    char board[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    ```
- _ represents an empty cell.

- X represents the user's move.

- O represents the computer's move.

## Game Logic
- The game is controlled by the following functions:

- printBoard(): Displays the current state of the game board.

- checkWinner(): Checks if there is a winner or if the game is a draw.

- isMovesLeft(): Checks if there are any empty cells left on the board.

- minimax(): The core of the Minimax algorithm. It recursively evaluates the board to find the best possible move for the AI.

- bestMoveForAI(): Determines the best move for the AI by evaluating all possible moves and selecting the one with the highest score.

- main(): Manages the game loop, takes user input, and alternates turns between the user and the computer.

## Minimax Algorithm
- The Minimax algorithm is a recursive function that generates a game tree, exploring all possible moves and outcomes:

    - The AI maximizes its score, trying to get the highest possible score (a win).

    - The user tries to minimize the AI's score (aiming to win).

- The score is assigned as follows:

    - 10: AI wins

    - -10: User wins

    - 0: Draw