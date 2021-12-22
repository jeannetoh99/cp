#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void solve() {
    int n,m; cin>>n>>m;
    unordered_map<string, iii> cars; // catalog, pickup cost, cost per km
    while (n--) {
        string N; int p,q,k; cin>>N>>p>>q>>k;
        cars[N] = {p,q,k};
    }
    unordered_map<string, string> spycars;
    map<string, int> spycost;
    string ignore, c;
    while (m--) {
        int t; string s,e; cin>>t>>s>>e;
        if (spycost.find(s) == spycost.end()) { spycars[s]=""; spycost[s]=0; }
        if (spycost[s] == -1) { cin>>ignore; continue; }
        if (e=="p") {
            cin >> c; 
            if (spycars[s] != "") { spycost[s] = -1; continue; }
            auto [p,q,k] = cars[c]; spycars[s] = c;
            spycost[s] += q;
        } else {
            int v; cin >> v;
            if (spycars[s] == "") { spycost[s] = -1; continue; } 
            auto [p,q,k] = cars[spycars[s]];
            if (e=="r") { 
                spycars[s] = ""; 
                spycost[s] += v*k; 
            } else {
                c = spycars[s];
                spycost[s] += ceil((double) p * v / 100);
            }
        }
    }
    for (auto it = spycost.begin(); it != spycost.end(); ++it) {
        auto [spy, cost] = *it;
        if (spycars[spy] != "" || spycost[spy] == -1) printf("%s INCONSISTENT\n", spy.c_str());
        else printf("%s %d\n", spy.c_str(), cost);
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}

