#include <bits/stdc++.h>
using namespace std;

int main() {

    int p; cin >> p;
    while (p--) {
        double k, n; cin >> k >> n;
        cout << k << " " << (int) ((n+1)*(n/2) + n) << "\n";
    }

}
