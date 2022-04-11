#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int w, l;

    int deltas[4][2] = {
        {-1, 0}, // left
        {0, -1}, // up
        {1, 0}, // right
        {0, 1} // down
    };

    int t = 1;
    while (cin >> w >> l, w || l) {
        char grid[l][w];
        int x,y,d;
        for (int i=0; i<l; i++) {
            for (int j=0; j<w; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '*') {
                    y=i, x=j;
                    if (i==0) d=3;
                    else if (i == l-1) d=1;
                    else if (j == 0) d=2;
                    else if (j == w-1) d=0;
                }
            }
        }

        while (true) {
            // cout << x << " " << y << " " << d << " " << grid[y][x] << endl;
            x += deltas[d][0];
            y += deltas[d][1];
            char c = grid[y][x];
            if (c == '.') continue;
            if (c == 'x') {
                grid[y][x] = '&';
                break;
            }
            if (c == '/') {
                if (d == 0) d=3;
                else if (d==1) d=2;
                else if (d==2) d=1;
                else if (d==3) d=0;
            } else if (c == '\\') {
                if (d == 0) d=1;
                else if (d==1) d=0;
                else if (d==2) d=3;
                else if (d==3) d=2;
            }
        }
        
        cout << "HOUSE " << t << endl;
        for (int i=0; i<l; i++) {
            for (int j=0; j<w; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        t++;
    }

}
