#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;
    int ans = 1;
    int prev = 1e6 + 1;
    while (n--) {
        int x; cin >> x;
        if (x > prev) ans++;
        prev = x;
    }

    cout << ans << endl;
}
