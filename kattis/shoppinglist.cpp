#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n, m; cin >> n >> m;
    unordered_set<string> curr;
    for (int i=0; i<m; i++) {
        string x; cin >> x; curr.insert(x);
    }
    n--;
    while (n--) {
        unordered_set<string> next;
        for (int i=0; i<m; i++) {
            string x; cin >> x; 
            if (curr.count(x)) next.insert(x);
        }
        curr = next;
    }
    vector<string> res; res.assign(curr.begin(), curr.end());
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (string s : res) {
        cout << s << "\n";
    }
}
