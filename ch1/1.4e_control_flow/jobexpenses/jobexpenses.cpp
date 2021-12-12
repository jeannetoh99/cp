#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int N; cin >> N;
    ll e = 0;
    while (N--) {
        ll k; cin >> k;
        if (k < 0) {
            e += (k * -1);
        }
    }
    cout << e << endl;
}
