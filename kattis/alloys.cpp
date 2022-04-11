#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    double c; cin >> c;

    c = min(c, 1.0);
    
    cout << fixed << setprecision(6) << (c/2.0)*(c/2.0) << "\n";

}
