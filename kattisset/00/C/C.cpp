#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n,q; cin >> n >> q;
    pair<int, ll> persons[n]; // x, query number
    memset(persons, 0, sizeof(pair<int, ll>)*n);

    pair<int, ll> curr = {0, 0};

    int i,x; 
    for (ll j=1; j<=q; j++) {
        string cmd; cin >> cmd;
        if (cmd == "SET") {
            cin >> i >> x;
            persons[i-1] = {x, j};
        } else if (cmd == "PRINT") {
            cin >> i;
            if (persons[i-1].second > curr.second) {
                cout << persons[i-1].first << "\n";
            } else {
                cout << curr.first << "\n";
            }
        } else {
            cin >> x;
            curr = {x, j};
        }
    }

}
