#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int x; cin >> x;

    while (x > 9) {
        int p = 1;
        for (int i = 10; i <= 1000; i*=10) {
            int r = x % i;
            if (r > 0) p *= (r * 10 / i);
            x -= r;
        }
        x = p;
    }

    cout << x << endl;
}