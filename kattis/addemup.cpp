#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

unordered_map<int, int> flip = {
    {1, 1}, {2, 2}, {5, 5}, {6, 9}, {9, 6}, {8, 8}, {0, 0}
};

int flipped(int num) {
    string s = to_string(num);
    reverse(s.begin(), s.end());
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '3' || s[i] == '4' || s[i] == '7') return 0;
        s[i-'0'] = '0'+flip[s[i-'0']];
    }
    return stoi(s);
}

int main() {
    int n, s; cin >> n >> s;
    vector<int> cards;
    while (n--) {
        int x; cin >> x;
        cards.push_back(x);
    }
    unordered_set<int> seen;
    for (int x : cards) {
        vector<int> pos;
        pos.push_back(s-x);
        if (flipped(s-x)) pos.push_back(flipped(s-x));
        if (flipped(x)) pos.push_back(s-flipped(x));
        if (flipped(s-flipped(x))) pos.push_back(flipped(s-flipped(x)));
        for (int p : pos) if (seen.count(p)) { cout << "YES\n"; return 0; }
        seen.insert(x);
    }
    cout << "NO\n";
}
