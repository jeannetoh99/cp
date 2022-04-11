#include <bits/stdc++.h>
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////

void solve() {
    int r,c; cin >> r >> c;
    vector<string> grid(r, "");
    for (int i=0;i<r;i++) cin >> grid[i];
    for (int i=r-1;i>=0;i--) {
        for (int j=c-1;j>=0;j--) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        cout << "Test " << i << "\n";
        solve();
    }
}
