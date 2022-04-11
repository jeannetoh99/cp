#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int a,b,c; cin >> a >> b >> c;
        if (a + b == c 
            || abs(a - b) == c
            || (double) a / (double) b == c
            || (double) b / (double) a == c  
            || a * b == c) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
}
