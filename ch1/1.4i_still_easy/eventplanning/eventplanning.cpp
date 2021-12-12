#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n, b, h, w; cin>>n>>b>>h>>w;

    int cost = 1e9;

    while (h--) {
        int p; cin >> p;
        for (int i = 0; i < w; i++) {
            int m; cin >> m;

            if (m >= n && n*p <= b && n*p < cost) {
                cost = n*p;
            } 
        }
    }

    if (cost == 1e9) {
        printf("stay home\n");
    } else {
        printf("%d\n", cost);
    }

}
