#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<iii, null_type, less<iii>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    vector<iii> teams; for (int i=1; i<=n; i++) teams.push_back({0,0,i});
    ost tree; for (iii t : teams) tree.insert(t);

    while (m--) {
        int t, p; cin >> t >> p;
        iii &team = teams[t-1];
        tree.erase(tree.find(team));
        get<0>(team)--;
        get<1>(team)+=p;
        tree.insert(team);
        cout << tree.order_of_key(teams[0]) + 1 << endl;
    }
}
