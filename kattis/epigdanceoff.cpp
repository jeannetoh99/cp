#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n, m; cin >> n >> m;

    char frame[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> frame[i][j];
        }
    }

    int res = 0;
    bool found = false;

    for (int j = 0; j < m; j++) {
        bool empty = true;
        for (int i = 0; i < n; i++) {
            if (frame[i][j] == '$') {
                if (!found) res++;
                found = true;
                empty = false;
            }
        }
        if (empty) found = false;
    }

    cout << res << endl;
}
