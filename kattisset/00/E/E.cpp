#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c; cin >> c; // # of companies

    vector<iii> records; // company, day, shares traded
    vector<vector<int>> company(c, vector<int>(365, 0));
    unordered_set<int> traded;

    for (int i=0; i<c; i++) {
        int k; cin >> k; // # of records for company
        for (int j=0; j<k; j++) {
            int n, d; cin >> n >> d;
            records.push_back({i, d, n});
        }
    }

    sort(records.begin(), records.end());

    for (iii r : records) {
        int c,d,n;
        tie (c, d, n) = r;
        fill(company[c].begin()+d-1, company[c].end(), n);
        traded.insert(d-1);
    }

    bool first = true;
    for (int i=0; i<365; i++) {
        if (traded.find(i) == traded.end()) continue;
        int shares = 0;
        for (int j=0; j<c; j++) shares += company[j][i];
        if (first) first = false; else cout << " ";
        cout << shares;
    }
    cout << "\n";
}
