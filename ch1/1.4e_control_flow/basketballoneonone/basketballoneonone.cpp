#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    char p;
    int s;

    int A = 0;
    int B = 0;

    bool winByTwo = false;

    while(scanf("%c %d", &p, &s)) {
        if (p == 'A') {
            A += s;
        } else {
            B += s;
        }
        if (A == 10 && B == 10) {
            winByTwo = true;
        } else if (A >= 11 && !winByTwo) {
            cout << "A" << endl;
            return 0;
        } else if (B >= 11 && !winByTwo) {
            cout << "B" << endl;
            return 0;
        } else if (winByTwo && abs(A-B) >= 2) {
            cout << (A > B ? "A" : "B") << endl;
            return 0;
        }
    }
}
