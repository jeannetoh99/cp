#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int k, n; cin >> k >> n;

    int tt = 0;
    int p = k -1;

    for (int i = 0; i < n; i++) {
        int t; char z;
        cin >> t >> z;

        tt += t;
        if (tt >= 210) {
            printf("%d\n", p + 1);
            return 0;
        }
        if (z == 'T') {
            p = (p+1) % 8;
        }
    }
}
