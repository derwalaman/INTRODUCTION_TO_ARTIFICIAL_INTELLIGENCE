#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

vector<int> bfs(unordered_map<int, vector<int> >& graph, int start, int goal) {
    unordered_set<int> visited;
    queue<vector<int>> q;
    q.push({start});
    visited.insert(start);

    cout << "BFS Traversal Order : ";

    while(!q.empty()){
        vector<int> path = q.front();
        q.pop();
        int current = path.back();
        cout << current << " ";

        if(current == goal) return path;

        for(int neighbor : graph[current]) {
            if(visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }
    return {};
}

bool dfsUtil(unordered_map<int, vector<int> >& graph, int current, int goal, unordered_set<int>& visited, vector<int>& path) {
    visited.insert(current);
    path.push_back(current);
    cout << current << " ";

    if(current == goal) return true;

    for(int neighbor : graph[current]) {
        if(visited.find(neighbor) == visited.end()) {
            if(dfsUtil(graph, neighbor, goal, visited, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

vector<int> dfs(unordered_map<int, vector<int> >& graph, int start, int goal) {
    unordered_set<int> visited;
    vector<int> path;
    cout << "DFS Traversal Order: ";
    dfsUtil(graph, start, goal, visited, path);
    return path;
}

void printPath(const vector<int>& path){
    if(path.empty()){
        cout << "No path found." << endl;
        return;
    } 

    cout << "\n Path from start to goal: ";
    for(int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    unordered_map<int, vector<int> > graph;
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1, 5};
    graph[5] = {2, 4};

    int start = 0, goal = 5;

    // BFS
    vector<int> bfsPath = bfs(graph, start, goal);
    printPath(bfsPath);

    cout << "\n--------------------------\n";

    // DFS
    vector<int> dfsPath = dfs(graph, start, goal);
    printPath(dfsPath);

    return 0;
}