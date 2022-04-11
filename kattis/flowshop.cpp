#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n, m; cin >> n >> m;

    int t[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> t[i][j];
        }
    }

    int ct[n][m];

    ct[0][0] = t[0][0];
    for (int j=1; j<m; j++) ct[0][j] = ct[0][j-1] + t[0][j];
    for (int i=1; i<n; i++) ct[i][0] = ct[i-1][0] + t[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int s = max(ct[i-1][j], ct[i][j-1]);
            ct[i][j] = s + t[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        if (i!=0) cout << " ";
        cout << ct[i][m-1];
    }
    cout << endl;

}
