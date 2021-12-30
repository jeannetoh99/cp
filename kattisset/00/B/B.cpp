#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ll n,t; cin >> n >> t;

    vector<pair<ll, ll>> remote, instore; // d, k
    while (n--) {
        ll d, k; char s; cin >> d >> s >> k;
        if (s == 'R') remote.push_back({d, k});
        else instore.push_back({d, k});
    }

    sort(remote.begin(), remote.end());
    sort(instore.begin(), instore.end());

    ll r=0, i=0;
    ll rt=0, it=0;
    priority_queue<ll, vector<ll>, greater<ll>> technicians;
    while (t--) technicians.push(1);

    while (r < remote.size() || i < instore.size()) {
        ll t = technicians.top(); technicians.pop();
        if (i < instore.size() && (r == remote.size() || instore[i].first <= t || instore[i].first <= remote[r].first)) {
            ll nt = max(instore[i].first, t) + instore[i].second;
            it += (nt - instore[i].first); i++; technicians.push(nt);
        } else {
            ll nt = max(remote[r].first, t) + remote[r].second;
            rt += (nt - remote[r].first); r++; technicians.push(nt);
        }
    }

    long double O = instore.empty() ? 0 : (long double) it / instore.size();
    long double R = remote.empty() ? 0 : (long double) rt / remote.size();

    cout << fixed << setprecision(9) << O << " " << R << endl;

}
