#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n, l, p; cin >> n >> l >> p;

    int ld = 0;
    int mp = 0;

    int cars[n];
    memset(cars, 0, sizeof(cars));

    while (p--) {
        int x; cin >> x;
        int carNo;
        if (x >= n * l) {
            carNo = n;
        } else {
            carNo = x/l + 1;
        }
        cars[carNo - 1]++;

        int d = abs(carNo * l - (l/2) - x);
        if (d > ld) ld = d;
    }

    cout << ld << endl;

    for (int i = 0; i < n; i++) {
        if (cars[i] > mp) mp = cars[i];
    }

    cout << mp << endl;

}
