#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    string x, y; cin >> x >> y;

    int xs = (x.size() - 1) / 3;
    int ys = (y.size() - 1) / 3;

    int xys = xs * ys;

    for (int i = 0; i < xys; i++) {
        cout << "S(";
    }

    cout << "0";

    for (int i = 0; i < xys; i++) {
        cout << ")";
    }

    cout << endl;

}
