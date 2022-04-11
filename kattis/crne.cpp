#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ll n; cin >> n;
    ll h = n/2;
    ll v = n - h;
    cout << (h+1) * (v+1) << "\n";

}
