#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll r, e, c;
        cin >> r >> e >> c;
        if (r > e - c) {
            cout << "do not advertise" << endl;
        } else if (r < e - c) {
            cout << "advertise" << endl;
        } else {
            cout << "does not matter" << endl;
        }
    }
}
