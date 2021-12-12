#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;

    int t[n];

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int lt = 41;
    int d = -1;

    for (int i = 0; i < n - 2; i++) {
        int ht = max(t[i], t[i+2]);
        if (ht < lt) {
            lt = ht;
            d = i + 1;
        }
    }

    cout << d << " " << lt << endl;

}
