#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

ii getDimensions(int n) {

    int R = 1;
    for (int r = 2; r <= floor(sqrt(n)); r++) {
        if (n % r == 0) R = r;
    }

    return make_pair(R, n/R);
}

int main() {

    string message; cin >> message;
    ii dim = getDimensions(message.size());
    int r = dim.first;
    int c = dim.second;

    char grid[r][c];

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            grid[i][j] = message.at(j*r+i);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j];
        }
    }
    cout << endl;

}
