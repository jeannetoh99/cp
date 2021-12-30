#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m; // n = num of islands, m = num of bridges
    
    vector<int> armySize;
    vector<vector<int>> AL(n, vector<int>());
    
    while (m--) {
        int u, v; cin >> u >> v;
        AL[u-1].push_back(v-1);
        AL[v-1].push_back(u-1);
    }

    for (int i=0; i<n; i++) {
        int s; cin >> s;
        armySize.push_back(-s);
    }

    priority_queue<ii> toAttack; // army size, island number
    vector<bool> visited(n, false);

    int currSize = armySize[0];
    visited[0] = true;

    for (int neigh : AL[0]) {
        toAttack.emplace(armySize[neigh], neigh);
        visited[neigh] = true;
    }

    while (!toAttack.empty()) {
        ii island = toAttack.top(); toAttack.pop();
        if (island.first <= currSize) break;
        currSize += island.first;
        for (int neigh : AL[island.second]) {
            if (visited[neigh]) continue;
            visited[neigh] = true;
            toAttack.emplace(armySize[neigh], neigh);
        }
    }

    cout << -currSize << endl;
}
