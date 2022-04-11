#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void post_order_dfs(string f, unordered_set<string> &visited, 
    unordered_map<string, vector<string>> &adj_list, stack<string> &res) {
    visited.insert(f);
    for (string n : adj_list[f]) {
        if (visited.find(n) != visited.end()) continue;
        post_order_dfs(n, visited, adj_list, res);
    }
    res.push(f);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string line; getline(cin, line);
    unordered_map<string, vector<string>> adj_list;

    while (n--) {
        string f; getline(cin, f, ':');
        string deps; getline(cin, deps);
        istringstream ss(deps);
        string d;
        while (ss >> d) {
            adj_list[d].push_back(f);
        }
    }

    string f; cin >> f;
    unordered_set<string> visited;
    stack<string> res;

    post_order_dfs(f, visited, adj_list, res);

    while (!res.empty()) {
        cout << res.top() << endl;
        res.pop();
    }
}
