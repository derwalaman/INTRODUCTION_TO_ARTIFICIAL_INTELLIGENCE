#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// List of variables
vector<string> variables = {"A_X", "A_Y", "B_X", "B_Y", "C_X", "C_Y"};

// Function to check if current assignment satisfies all constraints
bool isSatisfying(unordered_map<string, bool> assignment) {
    // Constraint 1: A must be done before B
    if ((assignment["B_X"] && !(assignment["A_X"] || assignment["A_Y"])) ||
        (assignment["B_Y"] && !(assignment["A_X"] || assignment["A_Y"]))) {
        return false;
    }

    // Constraint 2: B must be done by X only
    if (assignment["B_Y"]) {
        return false;
    }

    // Constraint 3: C must be done by either X or Y
    if (!(assignment["C_X"] || assignment["C_Y"])) {
        return false;
    }

    // Only one worker per task
    if (assignment["A_X"] && assignment["A_Y"]) return false;
    if (assignment["B_X"] && assignment["B_Y"]) return false;
    if (assignment["C_X"] && assignment["C_Y"]) return false;

    return true;
}

// DPLL Recursive Solver
bool DPLL(int idx, unordered_map<string, bool> assignment) {
    if (idx == variables.size()) {
        if (isSatisfying(assignment)) {
            // Print the satisfying assignment
            cout << "Satisfying Assignment Found:\n";
            for (auto var : variables) {
                cout << var << " = " << (assignment[var] ? "True" : "False") << endl;
            }
            return true;
        }
        return false;
    }

    string var = variables[idx];

    // Try assigning True
    assignment[var] = true;
    if (DPLL(idx + 1, assignment)) return true;

    // Try assigning False
    assignment[var] = false;
    if (DPLL(idx + 1, assignment)) return true;

    return false;
}

int main() {
    unordered_map<string, bool> assignment;
    cout << "Starting DPLL Solver for Task Scheduling...\n";

    if (!DPLL(0, assignment)) {
        cout << "No satisfying assignment found.\n";
    }

    return 0;
}
