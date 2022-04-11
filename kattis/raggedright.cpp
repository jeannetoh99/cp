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

    vector<string> lines;
    
    string s; 
    int n  = 0;
    while (getline(cin, s)) {
        lines.push_back(s);
        n = max(n, (int) s.size());
    }

    int res = 0;
    for (int i=0; i<lines.size()-1; i++) {
        string l = lines[i];
        res += (n-l.size())*(n-l.size());
    }

    cout << res << "\n";

}
