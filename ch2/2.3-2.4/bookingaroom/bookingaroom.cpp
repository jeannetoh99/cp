#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int r, n; cin >> r >> n;

    if (r == n) {
        cout << "too late\n";
        return 0;
    }

    bool rooms[r];
    memset(rooms, false, sizeof(bool)*r);

    while(n--) {
        int x; cin >> x;
        rooms[x-1] = true;
    }

    for (int i=0;i<r;i++) {
        if (!rooms[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
}
