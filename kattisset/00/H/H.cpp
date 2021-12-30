#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define ld long double
using namespace std;

struct Eqn {
    ld a, b, c;
};

ld f(Eqn e, ld t) {
    return e.a*t*t + e.b*t + e.c;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pair<ld, Eqn>> ts;
    ld A=0, B=0, C=0;
    while (n--) {
        ld a,b,c,t; cin>>a>>b>>c>>t;
        ts.push_back({t, {a,b,c}});
        A+=a; B+=b; C+=c;
    }

    sort(ts.begin(), ts.end(), [](pair<ld, Eqn> a, pair<ld, Eqn> b) {
        return a.first < b.first;
    });

    vector<pair<ld, Eqn>> eqns;
    Eqn prev = {A, B, C};
    ld prevt = -0.000000000000000001;
    for (auto t : ts) {
        if (t.first != prevt) eqns.push_back({prevt, prev});
        prev = {prev.a - t.second.a, prev.b - t.second.b, prev.c - t.second.c};
        prevt = t.first;
    }
    eqns.push_back({prevt, prev});
    eqns.push_back({(ld) 100000, {0,0,0}});
    
    ld maxH = 0;
    for (int i=0; i<eqns.size()-1; i++) {
        auto e = eqns[i];
        ld lo = e.first;
        ld hi = eqns[i+1].first;
        Eqn eq = e.second;
        ld h = max(f(eq, lo+0.000000000000000001), f(eq, hi));
        ld peak = -eq.b/(eq.a*2);
        if (eq.a < 0 && lo < peak && hi >= peak) h = max(h, f(eq, peak));
        maxH = max(h, maxH);
    }

    cout << fixed << setprecision(9) << maxH << "\n";
}
