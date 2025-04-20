#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <set>

using namespace std;

// Graph representation
unordered_map<string, vector<pair<string, int>>> graph = {
    {"A", {{"B", 2}, {"D", 1}}},
    {"B", {{"A", 2}, {"C", 3}, {"E", 2}}},
    {"C", {{"B", 3}, {"F", 4}}},
    {"D", {{"A", 1}, {"E", 5}}},
    {"E", {{"D", 5}, {"B", 2}, {"F", 1}}},
    {"F", {{"E", 1}, {"C", 4}}}
};

// ========= UNIFORM COST SEARCH =========

struct Node {
    string city;
    int cost;
    vector<string> path;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

pair<vector<string>, int> uniformCostSearch(string start, string goal, int& nodesExplored) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<string> visited;
    pq.push({start, 0, {start}});
    nodesExplored = 0;

    while(!pq.empty()){
        Node curr = pq.top();
        pq.pop();
        nodesExplored++;

        if(curr.city == goal) return {curr.path, curr.cost};

        if(visited.find(curr.city) != visited.end()) continue;
        visited.insert(curr.city);

        for (auto neighbor : graph[curr.city]) {
            if (visited.find(neighbor.first) == visited.end()) {
                vector<string> newPath = curr.path;
                newPath.push_back(neighbor.first);
                pq.push({neighbor.first, curr.cost + neighbor.second, newPath});
            }
        }
    }
    return {{}, -1}; // No path found
}

// ========= ITERATIVE DEEPENING SEARCH =========

bool dls(string current, string goal, int limit, set<string> &visited, vector<string> &path, int cost, int &explored, int &finalCost) {
    explored++;
    path.push_back(current);
    visited.insert(current);

    if (current == goal) {
        finalCost = cost;
        return true;
    }

    if(limit <= 0){
        path.pop_back();
        return false;
    }

    for (auto neighbor : graph[current]) {
        if (visited.find(neighbor.first) == visited.end()) {
            if (dls(neighbor.first, goal, limit - 1, visited, path, cost + neighbor.second, explored, finalCost)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

pair<vector<string>, int> iterativeDeepeningSearch(string start, string goal, int maxDepth, int& explored) {
    for(int depth = 0; depth <= maxDepth; depth++){
        explored = 0;
        set<string> visited;
        vector<string> path;
        int finalCost = -1;
        if (dls(start, goal, depth, visited, path, 0, explored, finalCost)) {
            return {path, finalCost};
        }
    }
    return {{}, -1}; // No path found
}

// ========= MAIN DRIVER =========
void runDeliveryAgent(string agent, string start, string goal, int maxDepth = 10) {
    cout << "\n======================" << endl;
    cout << "Agent: " << agent << " | Start: " << start << " | Goal: " << goal << endl;

    int exploredUCS = 0, exploredIDS = 0;

    auto [pathUCS, costUCS] = uniformCostSearch(start, goal, exploredUCS);
    auto [pathIDS, costIDS] = iterativeDeepeningSearch(start, goal, maxDepth, exploredIDS);

    cout << "\n🔵 Uniform Cost Search (UCS):\n";
    if (!pathUCS.empty()) {
        cout << "Path: ";
        for (auto &p : pathUCS) cout << p << " ";
        cout << "\nCost: " << costUCS << "\nNodes Explored: " << exploredUCS << endl;
    } else {
        cout << "No path found.\n";
    }

    cout << "\n🟠 Iterative Deepening Search (IDS):\n";
    if (!pathIDS.empty()) {
        cout << "Path: ";
        for (auto &p : pathIDS) cout << p << " ";
        cout << "\nCost: " << costIDS << "\nNodes Explored: " << exploredIDS << endl;
    } else {
        cout << "No path found.\n";
    }

    cout << "======================\n";
}

int main() {
    runDeliveryAgent("Agent 1", "A", "F");
    runDeliveryAgent("Agent 2", "D", "C");
    return 0;
}