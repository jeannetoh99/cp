#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int S; cin >> S;
    printf("%d:\n", S);

    for (int i = 1; i <= S / 2; i++) {
        // same number of more/less rows
        // or every row same number
        // last row is more
        if (i != 1 && (S % (2 * i) == 0 || S % (2 * i) == i)) {
            printf("%d,%d\n", i, i);
        }
        if (S % (2 * i + 1) == 0|| S % (2 * i + 1) == i + 1) {
            printf("%d,%d\n", i+1, i);
        }
    }
}
