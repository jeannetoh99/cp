#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

int main() {

    int x, y; cin >> x >> y;
    int n; cin >> n;

    string inst[n];

    for (int i = 0; i < n; i++) {
        cin >> inst[i];
    }

    string types[3] = {"Left", "Forward", "Right"};
    ii deltas[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (inst[i] == types[j]) continue;
            int cx = 0, cy = 0;
            int d = 0;
            for (int k = 0; k < n; k++) {
                string ci = inst[k];
                if (k == i) ci = types[j];
                if (ci == "Right") {
                    d = (d+1) % 4;
                } else if (ci == "Left") {
                    d = (d+4-1) % 4;
                } else {
                    cx += deltas[d].first;
                    cy += deltas[d].second;
                }
            }
            if (cx == x && cy == y) {
                printf("%d %s\n", i + 1, types[j].c_str());
                return 0;
            }
        }
    }

}
