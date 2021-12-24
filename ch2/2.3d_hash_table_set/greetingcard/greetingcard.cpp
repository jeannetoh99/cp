#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

int main() {

    vector<ii> divisors;

    for (int i=0; i<=2018; i++) {
        for (int j=0; j<=2018; j++) {
            if (i*i+j*j == 2018*2018) {
                if (i == 0) {
                    divisors.push_back({i, j});
                    divisors.push_back({i, -j});
                } else if (j == 0) {
                    divisors.push_back({-i, j});
                    divisors.push_back({i, j});
                } else {
                    divisors.push_back({i, j});
                    divisors.push_back({-i, j});
                    divisors.push_back({i, -j});
                    divisors.push_back({-i, -j});
                }
            }
        }
    }

    unordered_set<ii, pair_hash> coords;

    int p; cin >> p;
    int res = 0;
    while (p--) {
        int x,y; cin >> x >> y;
        for (ii d : divisors) {
            if (coords.find({x+d.first, y+d.second}) != coords.end()) res++;
        }
        coords.insert({x, y});
    }

    cout << res << endl;

}
