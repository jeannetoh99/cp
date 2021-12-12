#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int t; cin >> t;

    while (t--) {
        int ng, nm; cin >> ng >> nm;
        ll gs[ng];
        ll ms[nm];

        for (int i = 0; i < ng; i++) {
            ll s; cin >> s;
            gs[i] = s;
        }

        for (int i = 0; i < nm; i++) {
            ll s; cin >> s;
            ms[i] = s;
        }

        sort(gs, gs + ng);
        sort(ms, ms + nm);

        int pg = 0;
        int pm = 0;

        while (pg < ng && pm < nm) {
            if (gs[pg] < ms[pm]) {
                pg++;
            } else {
                pm++;
            }
        }

        if (pg == ng) {
            printf("MechaGodzilla\n");
        } else {
            printf("Godzilla\n");
        }

    }

}
