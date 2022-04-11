#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll dx = abs(x2-x1);
        ll dy = abs(y2-y1);
        ll diff = abs(dy-dx);
        ll res = min(dx, dy) * 2;

        if (diff % 2 == 0) {
            res += diff * 2;
        } else {
            res += diff * 2 - 1;
        }

        cout << res << "\n";
    }

}
