#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n, dm; cin >> n >> dm;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        if (d > dm) {
            ans++;
        } else {
            break;
        }
    }
    if (ans == n) {
        cout << "It had never snowed this early!\n";
    } else {
        printf("It hadn't snowed this early in %d years!\n", ans);
    }
}
