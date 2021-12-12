#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int a, b; cin >> a >> b;
    int ops = 0;

    while (a > b) {
        if (a % 2 == 1) {
            a += 1;
            a /= 2;
            ops += 2;
        } else {
            a /= 2;
            ops++;
        }
    }

    while (a < b) {
        a++;
        ops++;
    }
    
    cout << ops << endl;
}
