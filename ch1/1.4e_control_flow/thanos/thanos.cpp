#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll p, r, f; cin >> p >> r >> f;
        int y = 0;
        while (p <= f) {
            p *= r;
            y++;
        }
        cout << y << endl;
    }
}
