#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 8;
const int POPULATION_SIZE = 30;
const int MAX_GENERATIONS = 10000;

vector<int> randomBoard() {
    vector<int> board;
    for (int i = 0; i < N; i++) {
        board.push_back(rand() % N);
    }
    return board;
}

// Fitness function (higher is better)
int calculateFitness(const vector<int>& board) {
    int fitness = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (board[i] != board[j] && abs(board[i] - board[j]) != abs(i - j)) {
                fitness++;
            }
        }
    }
    return fitness;
}

// Crossover two parents
vector<int> crossover(vector<int>& parent1, vector<int>& parent2) {
    vector<int> child;
    int crossover_point = rand() % N;
    for (int i = 0; i < crossover_point; ++i)
        child.push_back(parent1[i]);
    for (int i = crossover_point; i < N; ++i)
        child.push_back(parent2[i]);
    return child;
}

// Mutate a board
void mutate(vector<int>& board) {
    int row = rand() % N;
    int col = rand() % N;
    while (board[row] == col) {
        col = rand() % N; // Ensure the new column is different
    }
    board[row] = col;
}

void printBoard(const vector<int>& board){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    vector<vector<int>> population;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population.push_back(randomBoard());
    }

    int generation = 0;

    while (generation < MAX_GENERATIONS) {
        // Sort population by fitness -- higher fitness is better
        vector<pair<int, int>> fitness_with_index;
        for (int i = 0; i < POPULATION_SIZE; i++) {
            fitness_with_index.push_back({calculateFitness(population[i]), i});
        }
        sort(fitness_with_index.begin(), fitness_with_index.end(), greater<pair<int, int>>());
        
        if (fitness_with_index[0].first == (N * (N - 1)) / 2) {
            cout << "Solution found at generation " << generation << "!\n";
            int index = fitness_with_index[0].second;
            printBoard(population[index]);
            return 0;
        }

        // new generation
        vector<vector<int>> newPopulation;
        for (int i = 0; i < POPULATION_SIZE; ++i) {
            vector<int> parent1 = population[rand() % POPULATION_SIZE];
            vector<int> parent2 = population[rand() % POPULATION_SIZE];
            vector<int> child = crossover(parent1, parent2);
            if (rand() % 100 < 30) // 30% mutation
                mutate(child);
            newPopulation.push_back(child);
        }

        population = newPopulation;
        generation++;
    }

    return 0;
}
