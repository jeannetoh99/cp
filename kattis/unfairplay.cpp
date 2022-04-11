// Disclaimer: This code is a hybrid between old CP1-2-3 implementation of
// Edmonds Karp's algorithm -- re-written in OOP fashion and the fast
// Dinic's algorithm implementation by
// https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc
// This code is written in modern C++17 standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class max_flow {
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
    if (s == t) return f;                        // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap-flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx^1]);             // back edge
    rflow -= pushed;                             // back flow
    return pushed;
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

public:
  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }

  vector<int> getMatchRes(int m) {
      vector<int> res;
      for (int i=0; i<m; i++) {
        auto &[v, cap, flow] = EL[AL[i][2]];
        res.push_back(flow);
      }
      return res;
  }
};

///////////////////////////////// MAIN /////////////////////////////////

void solve(int n, int m) {
    vector<ll> teams(n, 0);
    for (int i=0; i<n; i++) cin >> teams[i];
    
    max_flow mf(2+m+n);
    int s=m+n, t=s+1;

    ll r = 0;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        mf.add_edge(s, i, 2);
        if (a==n) {
            mf.add_edge(i, m+a-1, 2);
            mf.add_edge(i, m+b-1, 0);
            r+=2;
        } else if (b==n) {
            mf.add_edge(i, m+a-1, 0);
            mf.add_edge(i, m+b-1, 2);
            r+=2;
        } else {
            mf.add_edge(i, m+a-1, 2);
            mf.add_edge(i, m+b-1, 2);
        }
    }

    ll maxP = teams[n-1] + r;

    for (int i=0; i<n; i++) {
        ll p = i == n-1 ? r : maxP - teams[i] - 1;
        if (p < 0) { cout << "NO\n"; return; }
        mf.add_edge(i+m, t, p);
    }

    ll flow = mf.dinic(s, t); 

    bool possible = flow == m*2;
    if (!possible) { cout << "NO\n"; return; }

    vector<int> res = mf.getMatchRes(m);

    for (int i=0; i<m; i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    int n,m;
    while (cin >> n >> m) solve(n, m);
}

