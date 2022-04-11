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

void solve(int n) {
    map<string, int> list;

    for (int i=0; i<n; i++) {
        string x; getline(cin, x);
        int j = x.find_last_of(' ');
        string animal = j == x.npos ? x : x.substr(j+1);
        transform(animal.begin(), animal.end(), animal.begin(), ::tolower);
        list[animal]++;
    }

    for (auto p : list) {
        cout << p.first << " | " << p.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; int n;
    while (cin >> n && n) {
        cout << "List " << t++ << ":\n";
        string x; getline(cin, x);
        solve(n);
    }
}
