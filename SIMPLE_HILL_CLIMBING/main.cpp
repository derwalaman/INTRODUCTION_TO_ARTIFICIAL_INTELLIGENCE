#include<iostream>
#include<vector>
#include <tuple>
#include <cmath>
using namespace std;

const int row = 5, col = 5;

vector<vector<int>> grid = {
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// directions 
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

// goal coordinates
int goalX = 4;
int goalY = 3;

// heuristic function
int heuristic(int x, int y){
    return abs(x - goalX) + abs(y - goalY);
}

bool isValid(int x, int y, vector<vector<bool>>& visited) {
    return (x >= 0 && y >= 0 && x < row && y < col &&
            grid[x][y] == 0 && !visited[x][y]);
}

bool hillClimb(int startX, int startY){
    int x = startX;
    int y = startY;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<pair<int, int>> path;

    while(true){
        visited[x][y] = true;
        path.push_back({x,y});

        if (x == goalX && y == goalY) {
            cout << "✅ Goal Reached!\nPath: ";
            for (auto& p : path) cout << "(" << p.first << "," << p.second << ") ";
            return true;
        }

        int minH = INT_MAX;
        int nextX = -1, nextY = -1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, visited)) {
                int h = heuristic(nx, ny);
                if (h < minH) {
                    minH = h;
                    nextX = nx;
                    nextY = ny;
                }
            }
        }
        // No better move found
        if (nextX == -1 || heuristic(nextX, nextY) >= heuristic(x, y)) {
            cout << "❌ Stuck at local maxima or blocked path.\nPath: ";
            for (auto& p : path) cout << "(" << p.first << "," << p.second << ") ";
            return false;
        }

        x = nextX;
        y = nextY;
    }
}

int main(){
    int startX = 0, startY = 0; // Start at 'S'
    hillClimb(startX, startY);
    return 0;
}