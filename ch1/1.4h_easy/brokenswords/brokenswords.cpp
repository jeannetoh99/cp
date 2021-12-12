#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;

    int tblr[4] = {0};

    while (n--) {
        for (int i = 0; i < 4; i++) {
            char c; cin >> c;
            tblr[i] += (c == '0' ? 1 : 0);
        }
    }

    int tb = tblr[0] + tblr[1];
    int lr = tblr[2] + tblr[3];

    int make = min(tb, lr) / 2;

    printf("%d %d %d\n", make, tb - 2 * make, lr - 2 * make);
}
