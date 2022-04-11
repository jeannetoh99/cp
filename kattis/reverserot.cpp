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

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

void solve(int r, string s) {
    string res;
    for (char c : s) {
        int i = c - 'A';
        if (c == '_') i = 26;
        if (c == '.') i = 27;
        res += letters[(i + r) % 28]; 
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int r; string s;
    while (cin >> r >> s) solve(r, s);
}
