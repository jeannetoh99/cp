#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n,m; cin >> n >> m;
    
    unordered_map<string, vector<pair<ll, string>>> AL;
    unordered_map<string, ll> cost;
    unordered_map<string, int> hops;

    AL["English"] = vector<pair<ll, string>>();
    cost["English"] = 0;
    hops["English"] = 0;
    while (n--) {
        string lang; cin >> lang;
        AL[lang] = vector<pair<ll, string>>();
        cost[lang] = 1e18;
        hops[lang] = 1e9;
    }

    while (m--) {
        string l1, l2; ll c; cin >> l1 >> l2 >> c;
        AL[l1].push_back({c, l2});
        AL[l2].push_back({c, l1});
    }

    ll totalCost = 0;
    set<tuple<int, ll, string>> pq; pq.emplace(0, 0, "English");
    unordered_set<string> visited;

    while (!pq.empty()) {
        int h; ll c; string l1;
        tie(h, c, l1) = *pq.begin(); pq.erase(pq.begin());
        totalCost += c;
        visited.insert(l1);
        for (auto neigh : AL[l1]) {
            string l2 = neigh.second;
            ll c = neigh.first;
            if (visited.find(l2) != visited.end()) continue;
            if (hops[l1] + 1 < hops[l2] || (hops[l1] + 1 == hops[l2] && c < cost[l2])) {
                if (pq.find({hops[l2], cost[l2], l2}) != pq.end()) pq.erase(pq.find({hops[l2], cost[l2], l2}));
                hops[l2] = hops[l1] + 1;
                cost[l2] = c;
                pq.insert({hops[l2], cost[l2], l2});
            }
        }
    }

    if (visited.size() != cost.size()) cout << "Impossible\n";
    else cout << totalCost << endl;
}
