#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {

    double c, x, m;
    cin >> c >> x >> m;

    bool driveable[6];
    int speed[6];

    for (int i = 0; i < 6; i++) {
        int s; double fe;
        cin >> s >> fe;

        double h = m / s;
        double cc = (c/2) - (h*x);
        double g = m / fe;

        driveable[i] = cc >= g;
        speed[i] = s;
    }

    for (int i = 5; i >= 0; i--) {
        if (driveable[i]) {
            printf("YES %d\n", speed[i]);
            return 0;
        }
    }

    printf("NO\n");
}
