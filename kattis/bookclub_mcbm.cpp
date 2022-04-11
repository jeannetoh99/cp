#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi match, vis;                                   // global variables
vector<vi> AL;

int Aug(int L) {
  if (vis[L]) return 0;                          // L visited, return 0
  vis[L] = 1;
  for (auto &R : AL[L])
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      return 1;                                  // found 1 matching
    }
  return 0;                                      // no matching
}

int main() {

    int n, m; cin >> n >> m;
    int V = 2*n, Vleft = n;                          // we ignore vertex 0
    AL.assign(n, {});
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        AL[a].push_back(b+n);
    }

    match.assign(V, -1);
    int MCBM = 0;

    for (int L=0; L < Vleft; ++L) {                        // (in random order)
        vis.assign(Vleft, 0);                        // reset first
        MCBM += Aug(L);                              // try to match f
    }

    if (MCBM == n) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
