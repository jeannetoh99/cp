#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n, r, k;
    cin >> n >> r >> k;

    int ans = k + abs(r-k);
    if (n > ans) {
        if ((n - ans) % 2 == 0) {
            ans = n;
        } else {
            ans = n + 1;
        }
    }
    ans += r;

    cout << ans << endl;
}
