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

    string s; cin >> s;

    vector<string> grid(5, string(4*s.size()+1, '.'));

    for (int i=0; i<s.size(); i++) {
        int c = (i+1)*4-2;
        grid[2][c] = s[i];
        if (i % 3 == 2) {
            grid[0][c] = '*';
            grid[1][c-1] = '*';
            grid[1][c+1] = '*';
            grid[2][c-2] = '*';
            grid[2][c+2] = '*';
            grid[3][c-1] = '*';
            grid[3][c+1] = '*';
            grid[4][c] = '*';
        } else {
            grid[0][c] = '#';
            grid[1][c-1] = '#';
            grid[1][c+1] = '#';
            if (grid[2][c-2] == '.') grid[2][c-2] = '#';
            if (grid[2][c+2] == '.') grid[2][c+2] = '#';
            grid[3][c-1] = '#';
            grid[3][c+1] = '#';
            grid[4][c] = '#';
        }
    }

    for (int i=0; i<5; i++) {
        cout << grid[i] << "\n";
    }
}
