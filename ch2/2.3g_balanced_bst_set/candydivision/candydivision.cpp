#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ll n; cin >> n;

    bool first = true;
    set<ll> res;

    for (ll i=0; i<sqrt(n); i++) {
        if (n % (i+1) == 0) {
            res.insert(i);
            res.insert(n/(i+1)-1);
        }
    }

    for (ll num : res) {
        if (first) first = false; else cout << " ";
        cout << num;
    }
    cout << endl;
}
