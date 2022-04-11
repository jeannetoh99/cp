#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ll au, bu, ar, br; cin >> au >> bu >> ar >> br;
    ll u = min(bu, au);
    ll res = ar * br + u;
    if (ar > 0) res += (bu - u);
    if (br > 0) res += (au - u);
    if (ar > 0 && br > 0) res += u;
    cout << res << "\n";
}
