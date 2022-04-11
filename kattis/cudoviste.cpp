#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int numCars(vector<vector<char>> &carpark, int r, int c) {
    int num = 0;
    for (int i=r; i<r+2; i++) {
        for (int j=c; j<c+2; j++) {
            if (carpark[i][j] == '#') return -1;
            if (carpark[i][j] == 'X') num++;
        }
    }
    return num;
}

int main() {

    int r, c; cin >> r >> c;
    vector<vector<char>> carpark(r, vector<char>(c, 0));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> carpark[i][j];
        }
    }

    int res[5] = {0};
    for (int i=0; i<r-1; i++) {
        for (int j=0; j<c-1; j++) {
            int num = numCars(carpark, i, j);
            if (num > -1) res[num]++;
        }
    }

    for (int i=0;i<5;i++) cout << res[i] << "\n";
}
