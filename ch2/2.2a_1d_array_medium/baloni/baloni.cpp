#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    unordered_map<int, int> arrows;

    int n; cin >> n;
    int total = 0;
    while (n--) {
        int h; cin >> h;
        if (arrows.find(h) != arrows.end()) {
            arrows[h]--;
            if (arrows[h] == 0) arrows.erase(h);
        } else {
            total++;
        }
        if (arrows.find(h-1) != arrows.end()) {
            arrows[h-1]++;
        } else {
            arrows.emplace(h-1, 1);
        }
    }
    cout << total << endl;
}
