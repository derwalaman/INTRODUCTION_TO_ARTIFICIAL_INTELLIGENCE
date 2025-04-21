#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

void printPath(const vector<string>& path) {
    for (const string& node : path) {
        cout << node << " ";
    }
    cout << endl;
}

void greedyBFS(unordered_map<string, vector<pair<string, int>>> graph, unordered_map<string, int> heuristic, string start, string goal) {
    auto compare = [&](const pair<int, vector<string>>& a, const pair<int, vector<string>>& b) {
        return a.first > b.first;
    };

    priority_queue<pair<int, vector<string>>, vector<pair<int, vector<string>>>, decltype(compare)> pq(compare);
    set<string> visited;

    pq.push({heuristic[start], {start}});
    int nodesExpanded = 0;

    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();

        int h = current.first;
        vector<string> path = current.second;
        string currentNode = path.back();

        if (visited.find(currentNode) != visited.end()) continue;
        visited.insert(currentNode);
        nodesExpanded++;

        if (currentNode == goal) {
            cout << "\n🔵 Greedy Best-First Search (GBFS):\n";
            cout << "Path: ";
            printPath(path);
            cout << "Total Cost (heuristic ignored): N/A" << endl;
            cout << "Nodes Expanded: " << nodesExpanded << endl;
            return;
        }

        for (auto neighbor : graph[currentNode]) {
            if (visited.find(neighbor.first) == visited.end()) {
                vector<string> newPath = path;
                newPath.push_back(neighbor.first);
                pq.push({heuristic[neighbor.first], newPath});
            }
        }
    }
    cout << "No path found using GBFS." << endl;
}

void aStarSearch(unordered_map<string, vector<pair<string, int>>> graph, unordered_map<string, int> heuristic, string start, string goal) {
    auto compare = [&](const pair<int, pair<int, vector<string>>>& a, const pair<int, pair<int, vector<string>>>& b) {
        return a.first > b.first;
    };

    priority_queue<pair<int, pair<int, vector<string>>>, vector<pair<int, pair<int, vector<string>>>>, decltype(compare)> pq(compare);
    set<string> visited;

    pq.push({heuristic[start], {0, {start}}});
    int nodesExpanded = 0;

    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();

        int f = current.first;
        int g = current.second.first;
        vector<string> path = current.second.second;
        string currentNode = path.back();

        if (visited.find(currentNode) != visited.end()) continue;
        visited.insert(currentNode);
        nodesExpanded++;

        if (currentNode == goal) {
            cout << "\n🟠 A* Search:\n";
            cout << "Path: ";
            printPath(path);
            cout << "Total Cost: " << g << endl;
            cout << "Nodes Expanded: " << nodesExpanded << endl;
            return;
        }

        for (auto neighbor : graph[currentNode]) {
            if (visited.find(neighbor.first) == visited.end()) {
                int newCost = g + neighbor.second;
                vector<string> newPath = path;
                newPath.push_back(neighbor.first);
                int fScore = newCost + heuristic[neighbor.first];
                pq.push({fScore, {newCost, newPath}});
            }
        }
    }
    cout << "No path found using A*." << endl;
}

int main() {
    unordered_map<string, vector<pair<string, int>>> graph;
    unordered_map<string, int> heuristic;

    // Graph edges: node -> {neighbor, cost}
    graph["A"] = {{"B", 1}, {"C", 3}};
    graph["B"] = {{"D", 3}, {"E", 1}};
    graph["C"] = {{"F", 5}};
    graph["D"] = {{"G", 2}};
    graph["E"] = {{"G", 1}};
    graph["F"] = {{"G", 2}};
    graph["G"] = {};

    // Heuristic values (estimated distance to goal)
    heuristic["A"] = 7;
    heuristic["B"] = 6;
    heuristic["C"] = 5;
    heuristic["D"] = 4;
    heuristic["E"] = 2;
    heuristic["F"] = 3;
    heuristic["G"] = 0;

    string start = "A";
    string goal = "G";

    cout << "Start: " << start << " | Goal: " << goal << endl;

    greedyBFS(graph, heuristic, start, goal);
    aStarSearch(graph, heuristic, start, goal);

    return 0;
}
