#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int m = 0;
        int p = 1;
        while (true) {
            int x; cin >> x;
            if (x == 0) break;
            if (p*2 < x) m += (x - p*2);
            p = x; 
        }
        cout << m << endl;
    }

}
