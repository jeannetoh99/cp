#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int k; cin >> k;
        int res = 1;
        while (k--) {
            int o; cin >> o;
            res += (o-1);
        }
        cout << res << "\n";
    }
}