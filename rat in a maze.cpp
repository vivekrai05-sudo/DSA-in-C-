#include <iostream>
#include <vector>
using namespace std;

bool issafe(int x, int y, int row, int col, int arr[3][3], vector<vector<bool>> &visited) {
    if (x >= 0 && x < row && y >= 0 && y < col && arr[x][y] == 1 && !visited[x][y]) {
        return true;
    }
    return false;
}

void solveMaze(int arr[3][3], int row, int col, int srcx, int srcy, vector<vector<bool>> &visited, vector<string> &path, string output) {
    // base case: reached destination
    if (srcx == row - 1 && srcy == col - 1) {
        path.push_back(output);
        return;
    }

    // Down -> (x+1, y)
    if (issafe(srcx + 1, srcy, row, col, arr, visited)) {
        visited[srcx + 1][srcy] = true;
        solveMaze(arr, row, col, srcx + 1, srcy, visited, path, output + 'D');
        visited[srcx + 1][srcy] = false; // backtrack
    }

    // Left -> (x, y-1)
    if (issafe(srcx, srcy - 1, row, col, arr, visited)) {
        visited[srcx][srcy - 1] = true;
        solveMaze(arr, row, col, srcx, srcy - 1, visited, path, output + 'L');
        visited[srcx][srcy - 1] = false;
    }

    // Right -> (x, y+1)
    if (issafe(srcx, srcy + 1, row, col, arr, visited)) {
        visited[srcx][srcy + 1] = true;
        solveMaze(arr, row, col, srcx, srcy + 1, visited, path, output + 'R');
        visited[srcx][srcy + 1] = false;
    }

    // Up -> (x-1, y)
    if (issafe(srcx - 1, srcy, row, col, arr, visited)) {
        visited[srcx - 1][srcy] = true;
        solveMaze(arr, row, col, srcx - 1, srcy, visited, path, output + 'U');
        visited[srcx - 1][srcy] = false;
    }
}

int main() {
    int maze[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}
    };

    int row = 3, col = 3;

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true; // mark source as visited

    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0, 0, visited, path, output);

    cout << "Printing the result: " << endl;
    for (auto i : path) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

