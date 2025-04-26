#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int N = 8;

// calculate conflicts
int calculateConflicts(const vector<int>& board) {
    int conflicts = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(board[i] == board[j] || abs(board[i] - board[j]) == abs(i - j)) {
                conflicts++;
            }
        }
    }
    return conflicts;
}

// Random Walk Search
bool solveRandomWalk(vector<int>& board, int maxSteps = 10000) {
    for(int step = 0; step < maxSteps; step++) {
        int currentConflicts = calculateConflicts(board);
        if(currentConflicts == 0) return true;

        int row = rand() % N;
        int bestCol = board[row];
        int minConflicts = currentConflicts;

        for(int col = 0; col < N; col++){
            if(col == board[row]) continue;
            vector<int> temp = board;
            temp[row] = col;
            int newConflicts = calculateConflicts(temp);
            if(newConflicts < minConflicts) {
                minConflicts = newConflicts;
                bestCol = col;
            }
        }
        board[row] = bestCol;
    }
    return false;
}

// Simulated Annealing Search
bool solveSimulatedAnnealing(vector<int>& board){
    double T = 100.0;
    double coolingRate = 0.99;
    int steps = 100000;

    for (int step = 0; step < steps && T > 0.01; ++step) {
        int currentConflicts = calculateConflicts(board);
        if (currentConflicts == 0) return true;

        int row = rand() % N;
        int newCol = rand() % N;

        vector<int> newBoard = board;
        newBoard[row] = newCol;

        int newConflicts = calculateConflicts(newBoard);
        int delta = newConflicts - currentConflicts;

        if (delta < 0 || exp(-delta / T) > (double)rand() / RAND_MAX) {
            board = newBoard;
        }

        T *= coolingRate;
    }
    return false;
}

// Display the board
void printBoard(const vector<int>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << (board[i] == j ? "Q " : ". ");
        cout << endl;
    }
}

int main(){
    
    srand(time(0)); // Seed for random number generation

    vector<int> board(N);
    for(int i = 0; i < N; i++){
        board[i] = rand() % N;
    }

    vector<int> board1 = board;
    vector<int> board2 = board;

    cout << "Random Walk Approach:\n";
    if (solveRandomWalk(board1)) {
        cout << "✅ Solution found!\n";
        printBoard(board1);
    } else {
        cout << "❌ No solution found.\n";
    }

    cout << "\nSimulated Annealing Approach:\n";
    if (solveSimulatedAnnealing(board2)) {
        cout << "✅ Solution found!\n";
        printBoard(board2);
    } else {
        cout << "❌ No solution found.\n";
    }

    return 0;

}