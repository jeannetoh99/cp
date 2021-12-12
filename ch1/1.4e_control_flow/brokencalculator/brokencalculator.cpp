#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;
    ll prev = 1;
    while (n--) {
        ll a, b, ans;
        char op;
        cin >> a >> op >> b;

        if (op == '+') {
            ans = a + b;
            ans -= prev;
        } else if (op == '-') {
            ans = a - b;
            ans *= prev;
        } else if (op == '*') {
            ans = a * b;
            ans = ans * ans;
        } else {
            if (a % 2 == 0) {
                ans = a / 2;
            } else {
                ans = (a + 1) / 2;
            }
        }

        cout << ans << endl;
        prev = ans;
    }

}
