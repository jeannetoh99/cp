#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    string a, b; cin >> a >> b;

    unordered_map<char, int> f_map;

    for (char c : a) {
        if (f_map.find(c) == f_map.end()) f_map.emplace(c, 0);
        f_map[c]++;
    }

    int r = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == b.at(i)) r++;
        char c = b.at(i);
        if (f_map.find(c) != f_map.end() && f_map[c] > 0) {
            f_map[c]--;
            s++;
        }
    }

    printf("%d %d\n", r, s-r);

}
