#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

bool solve(int n, int k) {
    return (k+1) % (1 << n) == 0;
}

int main() {

    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        int n, k; cin >> n >> k;
        printf("Case #%d: %s\n", i, solve(n,k) ? "ON" : "OFF");
    }

}
