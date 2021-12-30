#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize, setItems;                 // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    setItems.assign(N, 0);
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional
  int sizeOfSetItems(int i) { return setItems[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
    setItems[y] += setItems[x];
  }

  void insertItemToSet(int i) {
      setItems[findSet(i)]++;
  }
};

int main() {

    int n, l; cin >> n >> l;
    UnionFind drawers(l);

    while (n--) {
        int a, b; cin >> a >> b;
        drawers.unionSet(a-1, b-1);
        if (drawers.sizeOfSet(a-1) == drawers.sizeOfSetItems(a-1)) {
            cout << "SMECE\n";
        } else {
            drawers.insertItemToSet(a-1);
            cout << "LADICA\n";
        }
    }

}
