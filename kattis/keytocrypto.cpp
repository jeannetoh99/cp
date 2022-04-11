#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
#define vll vector<ll>
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define RFOR(i, j, k) for (int i=j ; i>=k ; i--)
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define INF (int)1e9
#define MOD 1000000007
#define fi first
#define se second
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string c, k, res; cin >> c >> k;

    for (int i=0; i<c.size(); i++) {
        char m = (c[i] - k[i] + 26) % 26 + 'A';
        res += m;
        k += m;
    }

    cout << res << "\n";
}
