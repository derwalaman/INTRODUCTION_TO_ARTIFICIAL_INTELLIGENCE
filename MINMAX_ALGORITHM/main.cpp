#include <iostream>
using namespace std;

char board[3][3] = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
};

// Display the board
void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if there's a winner
int checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '_' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return (board[i][0] == 'O') ? 10 : -10;
        if (board[0][i] != '_' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return (board[0][i] == 'O') ? 10 : -10;
    }
    // Diagonals
    if (board[0][0] != '_' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return (board[0][0] == 'O') ? 10 : -10;
    if (board[0][2] != '_' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return (board[0][2] == 'O') ? 10 : -10;

    return 0;
}

// Check if moves are left
bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int minimax(bool isAI) {
    int score = checkWinner();

    if (score == 10) return score;
    if (score == -10) return score;
    if (!isMovesLeft()) return 0;

    if (isAI) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'O';
                    best = max(best, minimax(false));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'X';
                    best = min(best, minimax(true));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

void bestMoveForAI() {
    int bestVal = -1000;
    int bestRow = -1, bestCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = 'O';
                int moveVal = minimax(false);
                board[i][j] = '_';

                if (moveVal > bestVal) {
                    bestRow = i;
                    bestCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    if (bestRow != -1 && bestCol != -1)
        board[bestRow][bestCol] = 'O';
}

int main() {
    int row, col;
    cout << "Tic-Tac-Toe: You (X) vs Computer (O)\n";

    while (true) {
        printBoard();
        cout << "Enter row and column (0-2): ";
        cin >> row >> col;

        if (board[row][col] != '_') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = 'X';

        if (checkWinner() == -10) {
            printBoard();
            cout << "You win!\n";
            break;
        }
        if (!isMovesLeft()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        bestMoveForAI();

        if (checkWinner() == 10) {
            printBoard();
            cout << "Computer wins!\n";
            break;
        }
        if (!isMovesLeft()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
