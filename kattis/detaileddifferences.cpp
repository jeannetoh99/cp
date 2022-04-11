#include <bits/stdc++.h>
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////

void solve() {
    string a, b; cin >> a >> b;
    string res(a.size(), ' ');
    for (int i=0; i<a.size();i++) {
        res[i] = a[i] == b[i] ? '.' : '*';
    }
    cout << a << "\n" << b << "\n" << res << "\n\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
