#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

bool outOfBounds(int x, int y) {
    return x < 0 || x >= 5 || y < 0 || y >= 5;
}

int main() {

    ii deltas[8] = {
        {-1, 2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {1, 2},
        {1, -2},
        {2, -1},
        {2, 1},
    };
    
    char grid[5][5];

    int count = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'k') count++;
        }
    }

    if (count != 9) {
        printf("invalid\n");
        return 0;
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (grid[i][j] == 'k') {
                for (int d=0; d<8; d++) {
                    int x = i + deltas[d].first;
                    int y = j + deltas[d].second;
                    if (outOfBounds(x, y)) continue;
                    if (grid[x][y] == 'k') {
                        printf("invalid\n");
                        return 0;
                    }
                }
            }
        }
    }

    printf("valid\n");

}
