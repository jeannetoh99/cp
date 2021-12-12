#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;
    ll fastest = 0;
    ll pt, pd;
    bool first = true;
    while (n--) {
        ll t, d; cin >> t >> d;
        if (first) {
            first = false;
        } else {
            ll speed = (d - pd) / (t - pt);
            if (speed > fastest) fastest = speed;
        }
        pt = t;
        pd = d;
    }
    cout << fastest << endl;
}
