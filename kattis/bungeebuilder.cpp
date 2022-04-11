#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;

    ll maxL = 0;
    ll maxH = 0;
    ll minM = 1e9;

    while (n--) {
        ll r; cin >> r;
        if (r > maxL) {
            ll h = maxL - minM;
            if (h > maxH) maxH = h;
            maxL = r;
            minM = 1e9;
        } else {
            ll h = r - minM;
            if (h > maxH) maxH = h;
            if (r < minM) minM = r;
        }
    }

    cout << maxH << endl;

}

