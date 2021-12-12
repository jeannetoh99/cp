#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
    int t; cin >> t;

    int r = abs(a-c) + abs(b-d);

    if (r <= t && (r-t) % 2 == 0) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
}
