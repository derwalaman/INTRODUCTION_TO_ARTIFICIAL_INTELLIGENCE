#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> colors = {"Red", "Green", "Blue"};
vector<string> regions = {"WA", "NT", "SA", "Q", "NSW", "V", "T"};

// Neighbors for each region
map<string, vector<string>> neighbors = {
    {"WA", {"NT", "SA"}},
    {"NT", {"WA", "SA", "Q"}},
    {"SA", {"WA", "NT", "Q", "NSW", "V"}},
    {"Q", {"NT", "SA", "NSW"}},
    {"NSW", {"SA", "Q", "V"}},
    {"V", {"SA", "NSW"}},
    {"T", {}}
};

// Function to check if color assignment is valid
bool isValid(string region, string color, map<string, string> &assignment) {
    for (string neighbor : neighbors[region]) {
        if (assignment[neighbor] == color) {
            return false;
        }
    }
    return true;
}

// MRV: Find the unassigned variable with minimum remaining colors
string selectUnassignedVariable(map<string, string> &assignment, map<string, vector<string>> &domains) {
    int min_options = 1e9;
    string selected = "";
    for(auto var : regions){
        if(assignment[var] == ""){
            int options = domains[var].size();
            if(options < min_options){
                min_options = options;
                selected = var;
            }
        }
    }
    return selected;
}

// LCV: Sort colors by least constraining value
vector<string> orderColors(string var, map<string, string> &assignment, map<string, vector<string>> &domains) {
    map<string, int> color_constraints;

    for (string color : domains[var]) {
        int count = 0;
        for (string neighbor : neighbors[var]) {
            if (assignment[neighbor] == "") { // Neighbor unassigned
                for (string neighbor_color : domains[neighbor]) {
                    if (neighbor_color == color) {
                        count++;
                    }
                }
            }
        }
        color_constraints[color] = count;
    }

    // Sort colors based on how few neighbors they block
    vector<pair<string, int>> sorted_colors(color_constraints.begin(), color_constraints.end());
    sort(sorted_colors.begin(), sorted_colors.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second < b.second;
    });

    vector<string> result;
    for (auto p : sorted_colors) {
        result.push_back(p.first);
    }
    return result;
}

bool backtrack(map<string, string>& assignment, map<string, vector<string> >& domains){
    bool complete = true;
    for (auto var : regions) {
        if (assignment[var] == "") {
            complete = false;
            break;
        }
    }
    if(complete) return true;

    // Select region using MRV
    string var = selectUnassignedVariable(assignment, domains);

    // try colors using LCV
    vector<string> ordered_colors = orderColors(var, assignment, domains);
    for (string color : ordered_colors) {
        if (isValid(var, color, assignment)) {
            assignment[var] = color;
            if (backtrack(assignment, domains))
                return true;
            assignment[var] = ""; // Undo assignment
        }
    }
    return false;
}

int main(){

    map<string, string> assignment;
    map<string, vector<string>> domains;

    for (string var : regions) {
        assignment[var] = "";
        domains[var] = colors;
    }

    if (backtrack(assignment, domains)) {
        cout << "Solution:\n";
        for (string var : regions) {
            cout << var << " -> " << assignment[var] << endl;
        }
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}