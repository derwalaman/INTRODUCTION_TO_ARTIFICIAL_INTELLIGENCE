# 8 Queens Problem with Genetic Algorithm

## Problem Overview

The aim of this program is to solve the **8-Queens problem** using a **Genetic Algorithm**. The problem involves placing 8 queens on a chessboard of size 8x8 such that no two queens threaten each other. The constraints are:

1. No two queens can occupy the same row.
2. No two queens can occupy the same column.
3. No two queens can occupy the same diagonal.

The program uses a genetic algorithm to find an optimal placement of queens that satisfies the constraints, beginning with a random placement of queens and iteratively improving it.

## Algorithm Overview

### Steps of the Genetic Algorithm:
1. **Initialization:** The population is randomly initialized with `k` different configurations (boards). In this implementation, the population size is 30.
2. **Fitness Function:** The fitness function evaluates how "good" a board configuration is by counting the number of non-attacking queen pairs.
3. **Selection and Crossover:** Two parent boards are selected based on their fitness and crossover is applied to generate a child board.
4. **Mutation:** A mutation occurs on the child board with a probability of 30%, where a queen is moved to a new position to introduce diversity in the population.
5. **Termination:** The algorithm runs for a maximum of `MAX_GENERATIONS` (10,000 in this case) or until a solution is found. A solution is considered found when a configuration has no conflicts (i.e., a fitness of `28`, as there are 28 non-attacking queen pairs on an 8x8 board).

## Code Explanation

### Main Components

1. **`randomBoard()`**: Generates a random board with one queen per row. Each element in the vector represents the column where the queen is placed in the corresponding row.
2. **`calculateFitness(const vector<int>& board)`**: This function calculates the fitness of a board configuration. The fitness is determined by counting the number of pairs of queens that do not attack each other (i.e., not in the same row, column, or diagonal).
3. **`crossover(vector<int>& parent1, vector<int>& parent2)`**: This function performs crossover between two parent boards, combining their genetic information to create a new child board.
4. **`mutate(vector<int>& board)`**: This function introduces mutation by randomly changing the position of a queen on the board.
5. **`printBoard(const vector<int>& board)`**: This function prints the current board in a readable format, with 'Q' representing a queen and '.' representing an empty space.

### Genetic Algorithm Process

1. **Initial Population:** The initial population is randomly generated with `POPULATION_SIZE` boards.
2. **Fitness Calculation and Sorting:** Each board in the population is evaluated for fitness, and the boards are sorted based on their fitness in descending order (higher fitness is better).
3. **Selection, Crossover, and Mutation:** Two parents are selected, and a child is generated through crossover. The child may undergo mutation with a 30% probability.
4. **Termination:** The algorithm checks if the best board in the population has a fitness equal to the maximum possible fitness. If a solution is found, the program prints the solution and terminates. If not, it continues evolving the population until the maximum number of generations is reached.
