#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define iii tuple<ll, ll, ll>
using namespace std;

// TODO: this solution is not fully correct yet.

ll solve(ll a, ll b) {
    
    ll d = 10;
    ll carry = 0;

    ll res = 0;
    while (a > 0 && b > 0) {
        ll a1 = (a - (a / d * d)) / (d/10);
        ll b1 = (b - (b / d * d)) / (d/10);

        // printf("%d %d %d %d %d %d\n", d, a, b, a1, b1, carry);

        ll sum = a1 + b1 + carry;
        carry = sum / 10;
        if (carry > 0) res++;

        a -= a1 * (d/10);
        b -= b1 * (d/10);
        d *= 10;
    }

    while (a > 0) {
        ll a1 = (a - (a / d * d)) / (d/10);
        ll sum = a1 + carry;
        carry = sum / 10;
        if (carry > 0) res++;
        a -= a1 * (d/10);
        d *= 10;
    }

    while (b > 0) {
        ll b1 = (b - (b / d * d)) / (d/10);
        ll sum = b1 + carry;
        carry = sum / 10;
        if (carry > 0) res++;
        b -= b1 * (d/10);
        d *= 10;
    }

    while (carry > 0) {
        carry = carry / 10;
        if (carry > 0) res++;
    }

    return res;
}

int main() {

    ll a,b;

    while (cin>>a>>b, a&&b ) {
        ll res = solve(a, b);
        if (res == 0) {
            cout << "No carry operation.\n";
        } else if (res == 1) {
            cout << "1 carry operation.\n";
        } else {
            cout << res << " carry operations.\n";
        }
    }

}
