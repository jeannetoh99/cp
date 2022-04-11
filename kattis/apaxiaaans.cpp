#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string x; cin >> x;
    string res = "";
    for (int i=0; i<x.size(); i++) {
        if (i == 0 || x[i] != x[i-1]) res+=x[i];
    }
    cout << res << "\n";
}
