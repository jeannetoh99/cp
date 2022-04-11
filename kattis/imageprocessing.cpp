#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int h,w,n,m; cin>>h>>w>>n>>m;

    int image[h][w];
    int kernel[n][m];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> image[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >=0; j--) {
            cin >> kernel[i][j];
        }
    }

    int res[h-n+1][w-m+1];

    for (int i = 0; i < h-n+1; i++) {
        for (int j = 0; j < w-m+1; j++) {
            int r = 0;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    r += image[i+k][j+l] * kernel[k][l];
                }
            }
            res[i][j] = r;
        }
    }

    for (int i = 0; i < h-n+1; i++) {
        for (int j = 0; j < w-m+1; j++) {
            if (j!=0) cout << " ";
            cout << res[i][j];
        }
        cout << endl;
    }

}
