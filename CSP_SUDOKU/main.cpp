#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 9;
vector<vector<int>> board(N, vector<int>(N));

// Function to check if placing num at (row, col) is valid
bool isValid(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to find the cell with Minimum Remaining Values (MRV)
pair<int, int> findMRVCell() {
    int minOptions = 10;
    pair<int, int> bestCell = {-1, -1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                int options = 0;
                for (int num = 1; num <= 9; num++) {
                    if (isValid(i, j, num)) {
                        options++;
                    }
                }
                if (options < minOptions) {
                    minOptions = options;
                    bestCell = {i, j};
                }
            }
        }
    }
    return bestCell;
}

// Function to get Least Constraining Values (LCV) ordering
vector<int> getLCV(int row, int col) {
    vector<pair<int, int>> count_value;

    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            int count = 0;
            // Check how many options this number would block for neighbors
            for (int i = 0; i < N; i++) {
                if (board[row][i] == 0 && isValid(row, i, num)) count++;
                if (board[i][col] == 0 && isValid(i, col, num)) count++;
            }
            count_value.push_back({count, num});
        }
    }
    sort(count_value.begin(), count_value.end()); // least blocking first
    vector<int> result;
    for (auto p : count_value) {
        result.push_back(p.second);
    }
    return result;
}

// Backtracking solver
bool solveSudoku() {
    auto [row, col] = findMRVCell();
    if (row == -1) {
        return true; // Puzzle solved
    }

    vector<int> candidates = getLCV(row, col);

    for (int num : candidates) {
        if (isValid(row, col, num)) {
            board[row][col] = num;
            if (solveSudoku()) {
                return true;
            }
            board[row][col] = 0; // undo
        }
    }
    return false;
}

// Function to print the Sudoku board
void printBoard() {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "------+-------+------\n";
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            if (board[i][j] == 0) cout << ". ";
            else cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the Sudoku board (use 0 for empty cells):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << "\nOriginal Sudoku Board:\n";
    printBoard();

    if (solveSudoku()) {
        cout << "\nSolved Sudoku Board:\n";
        printBoard();
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}