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
#define INF 1e18
#define MOD 1000000007
#define fi first
#define se second
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////

vll dijkstra(vector<vector<pair<int, ll>>> &AL, int n, int s) {
    vll dist(n, INF); dist[s] = 0;

    // (Modified) Dijkstra's algorithm
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; pq.push({0, s});

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto [d, u] = pq.top(); pq.pop();            // shortest unvisited u
        if (d > dist[u]) continue;                   // a very important check
        for (auto &[v, w] : AL[u]) {                 // all edges from u
            if (dist[u]+w >= dist[v]) continue;        // not improving, skip
            dist[v] = dist[u]+w;                       // relax operation
            pq.push({dist[v], v});                     // enqueue better pair
        }
    }

    return dist;
}

ll tsp(vector<vector<ll>> &apsp, vector<vector<ll>> &dp, int n, int visited_all, int mask, int pos)
{
	if (mask == visited_all){
		return apsp[pos][0];
	}
	if (dp[mask][pos] != -1){
		return dp[mask][pos];
	}
	
	ll ans = INF;
	
	for (int city =0; city < n; city++){
		if((mask & (1<<city))== 0){
			ll newAns = apsp[pos][city] + tsp(apsp, dp, n, visited_all, mask|(1<<city), city);
			ans = min(ans, newAns);
		}
	}
	return dp[mask][pos] = ans;
}

ll tsp(vector<vector<ll>> &apsp, int n) {
    int VISITED_ALL = (1<<n)-1;
    
    vector<vector<ll>> dp(1<<n, vll(n, -1));

    return tsp(apsp, dp, n, VISITED_ALL, 1, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin >> n >> m;

    vector<vector<pair<int, ll>>> AL(n, vector<pair<int, ll>>());
    
    FOR(i, 0, m) {
        int x, y; ll d; cin >> x >> y >> d;
        AL[x].emplace_back(y, d);
        AL[y].emplace_back(x, d);
    }

    int s; cin >> s;

    vector<int> loc; loc.push_back(0);
    FOR(i, 0, s) { int x; cin >> x; loc.push_back(x); }

    vector<vll> dists(s+1, vll());
    FOR(i, 0, s+1) {
        dists[i] = dijkstra(AL, n, loc[i]);
    }

    vector<vector<ll>> apsp(s+1, vector<ll>(s+1, 0));

    FOR(i, 0, s+1) {
        int u = loc[i];
        FOR(j, 0, s+1) {
            int v = loc[j];
            apsp[i][j] = dists[i][v];
        }
    }

    cout << tsp(apsp, s+1) << "\n";

}
