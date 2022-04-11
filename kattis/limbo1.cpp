#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int t; cin >> t; 
    while (t--) {
        ld l, r; cin >> l >> r;
        ld res = (l+r+2)/2.0*(l+r+1)-l;
        cout << (ll) res << "\n";
    }

}
