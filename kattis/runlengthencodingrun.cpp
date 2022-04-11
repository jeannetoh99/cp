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

    char c; string s, res; cin >> c >> s;

    if (c == 'E') {
        char ch = ','; int n = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ch) {
                if (n>0) { res += ch; res += n+'0'; }
                ch = s[i]; n = 1;
            } else {
                n++;
            }
        }
        res += ch; res += n+'0';
    } else {
        for (int i=0; i<s.size(); i+=2) {
            char ch = s[i]; int n = s[i+1]-'0';
            res += string(n, ch);
        }
    }

    cout << res << "\n";
}
