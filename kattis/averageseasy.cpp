#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int t; cin >> t;

    while (t--) {
        int c, e; cin >> c >> e;
        ll ctotal = 0, etotal = 0;
        vector<ll> cstudents(c, 0); vector<ll>estudents(e, 0);
        for (int i=0; i<c; i++) {
            cin >> cstudents[i];
            ctotal += cstudents[i];
        }
        for (int i=0; i<e; i++) {
            cin >> estudents[i];
            etotal += estudents[i];
        }

        ld cave = (ld) ctotal / c;
        ld eave = (ld) etotal / e;

        int res = 0;

        for (int i=0; i<c; i++) {
            ll nctotal = ctotal - cstudents[i];
            ll netotal = etotal + cstudents[i];
            ld ncave = (ld) nctotal / (c-1);
            ld neave = (ld) netotal / (e+1);

            // cout << cave << " " << ncave << " " << eave << " " << neave << "\n";

            if (ncave > cave && neave > eave) res++;
        }

        cout << res << "\n";
    }

}
