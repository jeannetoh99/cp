#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int t; cin >> t;
        if (t < 0) ans++;
    }
    cout << ans << endl;
}
