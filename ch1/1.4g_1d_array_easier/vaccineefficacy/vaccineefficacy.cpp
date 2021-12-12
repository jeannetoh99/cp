#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;

    int vn = 0; // vaxed, total
    int vi[3] = { 0 }; // vaxed, infected
    int cn = 0; // control, total
    int ci[3] = { 0 }; // control, infected

    while (n--) {
        char v; cin >> v;
        if (v == 'Y') {
            vn++;
            for (int i = 0; i < 3; i++) {
                char f; cin >> f;
                if (f == 'Y') {
                    vi[i]++;
                }
            }
        } else {
            cn++;
            for (int i = 0; i < 3; i++) {
                char f; cin >> f;
                if (f == 'Y') {
                    ci[i]++;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        double vir = 100.0 * vi[i] / vn;
        double cir = 100.0 * ci[i] / cn;
        if (vir >= cir) {
            cout << "Not Effective" << endl;
        } else {
            cout << fixed << setprecision(9) << 100.0 - (vir / cir) * 100.0 << endl;
        }
    }
}
