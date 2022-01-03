#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    int row[15] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3};
    int col[15] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2};
    int crow[15], ccol[15];

    for (int r=0; r<4; r++) {
        for (int c=0; c<4; c++) {
            char ch; cin >> ch;
            if (ch == '.') continue;
            int index = ch - 'A';
            crow[index] = r; ccol[index] = c;
        }
    }

    int res = 0;
    for (int i=0; i<15; i++) {
        res += abs(crow[i] - row[i]) + abs(ccol[i] - col[i]);
    }
    cout << res << endl;
}
