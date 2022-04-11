#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

int findNearestSqrt(int n, int sqrts[100]) {
    for (int i = 0; i < 100; i++) {
        if (n <= sqrts[i]) return i + 1;
    }
    return 0;
}

int main() {

    int sqrts[100];

    for (int i = 1; i <= 100; i++) {
        sqrts[i-1] = i*i;
    }

    int t; cin >> t;

    while (t--) {
        string line; cin >> line;
        int l = findNearestSqrt(line.size(), sqrts);
        char grid[l][l];
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                int n = i*l+j;
                if (n >= line.size()) {
                    grid[i][j] = '*';
                } else {
                    grid[i][j] = line.at(n);
                }
            }
        }

        for (int j = 0; j < l; j++) {
            for (int i = l-1; i >= 0; i--) {
                if (grid[i][j] == '*') continue;
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

}
