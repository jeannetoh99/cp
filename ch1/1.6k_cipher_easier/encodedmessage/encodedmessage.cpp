#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
    int t; cin >> t;
    while (t--) {
        string cipher; cin >> cipher;
        int n = sqrt(cipher.size());
        char grid[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = cipher.at(i*n+j);
            }
        }
        for (int j = n-1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

}
