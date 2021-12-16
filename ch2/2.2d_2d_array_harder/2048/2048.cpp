#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void print_grid(int grid[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != 0) cout << " ";
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void rotate_cw(int grid[4][4]) {
    int temp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[j][3-i] = grid[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

void rotate_acw(int grid[4][4]) {
    int temp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[i][j] = grid[j][3-i];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {

    int grid[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    int move; cin >> move;

    for (int i = 0; i < move; i++) rotate_acw(grid);

    vector<vector<int>> v(4, vector<int>(0));
    for (int i = 0; i < 4; i++) {
        int prev = 0;
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) continue;
            if (grid[i][j] == prev) {
                v[i].pop_back();
                v[i].push_back(prev * 2);
                prev = 0;
            } else {
                v[i].push_back(grid[i][j]);
                prev = grid[i][j];
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j >= v[i].size()) grid[i][j] = 0;
            else  grid[i][j] = v[i][j];
        }
    }
    for (int i = 0; i < move; i++) rotate_cw(grid);
    print_grid(grid);
}
