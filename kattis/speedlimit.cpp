#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (n == -1) break;

        ll d = 0;
        ll pt = 0;
        while (n--) {
            ll s, t; cin >> s >> t;
            d += s * (t - pt);
            pt = t;
        }

        printf("%d miles\n", d);
    }
}
