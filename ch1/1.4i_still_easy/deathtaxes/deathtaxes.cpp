#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    string e;
    int shares = 0;
    double avg = 0;

    while (true) {
        cin >> e;
        if (e == "buy") {
            int x, y; cin >> x >> y;
            avg = ((avg * shares) + (x*y)) / (shares + x);
            shares += x;
        } else if (e == "sell") {
            int x, y; cin >> x >> y;
            shares -= x; 
        } else if (e == "split") {
            int x; cin >> x;
            shares *= x;
            avg /= x;
        } else if (e == "merge") {
            int x; cin >> x;
            avg *= x;
            shares /= x;
        } else {
            double y; cin >> y;
            double profit = y - avg;
            double taxes = profit <= 0 ? 0 : profit * 0.3;
            double sale = shares * (y - taxes);

            cout << fixed << setprecision(3) << sale << endl;
            break;
        }
    }

}
