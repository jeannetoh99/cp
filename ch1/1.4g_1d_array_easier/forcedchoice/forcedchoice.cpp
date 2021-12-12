#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, p, s; cin >> n >> p >> s;

    while (s--) {
        int m; cin >> m;
        bool hasP = false;
        while (m--) {
            int x; cin >> x;
            if (x == p) hasP = true;
        }
        cout << (hasP ? "KEEP" : "REMOVE") << endl;
    }
}
