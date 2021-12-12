#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int r, c; cin >> r >> c;
    
    int maxR = 0;
    while (r--) {
        int x; cin >> x;
        maxR = max(maxR, x);
    }

    int maxC = 0;
    while (c--) {
        int x; cin >> x;
        maxC = max(maxC, x);
    }

    if (maxC == maxR) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }

    return 0;

}
