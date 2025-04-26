#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

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

void localBeamSearch(char start, char goal, int beamWidth){
    vector<vector<char>> paths;
    vector<int> costs;
    paths.push_back({start});
    costs.push_back(0);

    cout << "\nRunning Local Beam Search with beam size " << beamWidth << ":\n";

    while(!paths.empty()){
        vector<vector<char>> newPaths;
        vector<int> newCosts;

        for(int i = 0; i < paths.size(); i++){
            char current = paths[i].back();
            int currentCost = costs[i];

            if(current == goal){
                cout << "Path found: ";
                for (char c : paths[i]) cout << c << " ";
                cout << "\nTotal Cost: " << currentCost << endl;
                return;
            }

            for(auto& neighbor : graph[current]){
                char next = neighbor.first;
                int nCost = neighbor.second;
                if(find(paths[i].begin(), paths[i].end(), next) == paths[i].end()){
                    vector<char> newPath = paths[i];
                    newPath.push_back(next);
                    newPaths.push_back(newPath);
                    newCosts.push_back(currentCost + nCost);
                }
            }
        }
        
        // sort based on cost 
        vector<pair<int, int>> costIndexes;
        for(int i = 0; i < newCosts.size(); i++){
            costIndexes.push_back({newCosts[i], i});
        }
        sort(costIndexes.begin(), costIndexes.end());

        paths.clear();
        costs.clear();
        for (int i = 0; i < min(beamWidth, (int)costIndexes.size()); i++) {
            paths.push_back(newPaths[costIndexes[i].second]);
            costs.push_back(newCosts[costIndexes[i].second]);
        }
    }
    cout << "No path found from " << start << " to " << goal << " with beam width " << beamWidth << ".\n";
    cout << "------------------------------------\n";
}

int main(){
    vector<int> beamWidths = {2, 3, 4};
    for (int bw : beamWidths) {
        localBeamSearch('S', 'G', bw);
        cout << "------------------------------------\n";
    }
    return 0;
}