#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  vector<ll> setSum;
  int numSets;

public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
    setSum.assign(N, 0); for (int i = 0; i < N; ++i) setSum[i] = (ll) i;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
  ll sumOfSet(int i) { return setSum[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    setSum[y] += setSum[x];                      // combine set sums at y
    --numSets;                                   // a union reduces numSets
  }

  void move(int j, int i) { // move j to set containing i
    if (isSameSet(i,j)) return;
    int x = findSet(i);
    int y = findSet(j);
    for (int k=0; k<p.size(); k++) {
        if (p[k] == j) p[k] = y;
    }
    p[j] = x;
    setSize[x]++; setSize[y]--;
    setSum[x] += j; setSum[y] -= j;
  }
};

int main() {
    int n,m; 
    while (cin>>n>>m) {
        UnionFind UF(n+1);

        while (m--) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                int p,q; cin >> p >> q;
                UF.unionSet(p, q);
            } else if (cmd == 2) {
                int p,q; cin >> p >> q;
                UF.move(p, q);
            } else if (cmd == 3) {
                int p; cin >> p;
                printf("%d %lld\n", UF.sizeOfSet(p), UF.sumOfSet(p));
            }
        }
    }
}
