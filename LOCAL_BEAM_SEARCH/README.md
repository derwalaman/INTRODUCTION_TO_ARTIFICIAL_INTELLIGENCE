# Local Beam Search Algorithm

This program implements the **Local Beam Search** algorithm for finding a path in a graph. The algorithm explores multiple paths at each step and chooses the best paths based on cost (in this case, the sum of edge weights). The search continues until a goal node is found or all possible paths have been explored.

## Problem Description

Given a graph, the goal is to find the shortest path from a start node to a goal node using the **Local Beam Search** algorithm. The graph is represented by nodes and edges, where each edge has an associated cost. The algorithm maintains a set of paths and selects the best paths based on cost.

## Graph Representation

The graph is represented using an adjacency list where each node is connected to other nodes via edges with specific weights. Below is the graph used in the program:

```cpp
map<char, vector<pair<char, int>>> graph = {
    {'A',  {{'J', 19}, {'S', 26}}},
    {'B',  {{'A', 2}, {'I', 20}}},
    {'C',  {}},
    {'D',  {{'G', 9}}},
    {'E',  {{'B', 12}, {'H', 28}}},
    {'F',  {{'L', 35}, {'M', 11}, {'G', 22}}},
    {'G',  {}},
    {'H',  {{'F', 5}, {'K', 33}}},
    {'I',  {{'N', 7}, {'C', 31}, {'H', 8}}},
    {'J',  {{'N', 30}}},
    {'K',  {{'D', 3}, {'G', 14}}},
    {'L',  {{'C', 9}}},
    {'M',  {{'G', 16}}},
    {'N',  {{'L', 18}}},
    {'S',  {{'I', 6}}}
};
```

### Algorithm Details
1. Beam Search Initialization: The algorithm starts with a set of initial paths, each starting from the start node.

2. xploration of Neighbors: For each path, the algorithm explores its neighbors and extends the paths by adding one neighboring node at a time.

3. Path Selection: The new paths are ranked by cost, and only the best beamWidth number of paths are retained.

4. Goal Check: If any path reaches the goal node, the algorithm outputs the path and its total cost.

5. Termination: The search continues until a path to the goal is found or all possible paths are explored.

## Key Functions
- localBeamSearch(char start, char goal, int beamWidth): Implements the Local Beam Search algorithm. It takes a start node, a goal node, and a beam width, and finds the best path from start to goal.

- main(): Runs the beam search for different beam widths (2, 3, 4) from node 'S' to node 'G' and displays the results.