#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        int maxRes = 0;
        while (x != 0) {
            int y = x;
            int res = 0;
            while (y != 0) {
                y -= LSOne(y); res++;
            }
            x = x/10;
            maxRes = max(maxRes, res);
        }
        cout << maxRes << "\n";
    }
}
