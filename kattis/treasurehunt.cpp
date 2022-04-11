#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int r, c; cin >> r >> c;

    vector<vector<char>> grid = vector<vector<char>>(r, vector<char>(c , '-'));
    vector<vector<bool>> visited = vector<vector<bool>>(r, vector<bool>(c , false));

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> grid[i][j];
        }
    }

    int rr = 0;
    int cc = 0;
    int steps = 0;

    while (!visited[rr][cc]) {
        visited[rr][cc] = true;

        if (grid[rr][cc] == 'T') {
            cout << steps << endl;
            return 0;
        } else if (grid[rr][cc] == 'N') {
            rr -= 1;
        } else if (grid[rr][cc] == 'S') {
            rr += 1;
        } else if (grid[rr][cc] == 'E') {
            cc += 1;
        } else {
            cc -= 1;
        }

        if (rr < 0 || rr >= r || cc < 0 || cc >= c) {
            cout << "Out" << endl;
            return 0;
        }

        steps++;
    }

    cout << "Lost" << endl;
    return 0;
}
