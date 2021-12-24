#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    unordered_map<string, vector<int>> trips;

    while (n--) {
        string s; int y; cin >> s >> y;
        trips[s].push_back(y);
    }

    for (auto &trip : trips) {
        sort(trip.second.begin(), trip.second.end());
    }

    int q; cin >> q;
    while (q--) {
        string s; int k; cin >> s >> k;
        cout << trips[s][k-1] << endl;
    }

}
