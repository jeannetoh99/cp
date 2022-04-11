#include <bits/stdc++.h>
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string x; cin >> x; int n = x.size() / 2;
    string a = x.substr(0,n);
    string b = x.substr(n, n);

    int ar = 0, br = 0;
    for (int i=0; i<n; i++) {
        ar += a[i] - 'A';
        br += b[i] - 'A';
    }

    for (int i=0; i<n; i++) {
        a[i] = (a[i] - 'A' + ar) % 26 + 'A';
        b[i] = (b[i] - 'A' + br) % 26 + 'A';
    }

    for (int i=0; i<n; i++) {
        a[i] = (a[i] - 'A' + b[i] - 'A') % 26 + 'A';
    }

    cout << a << "\n";
}
