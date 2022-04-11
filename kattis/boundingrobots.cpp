#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int w, l;

    while (scanf("%d %d", &w, &l) && (w || l)) {
        int n; cin >> n;
        int rx = 0, ry = 0, x = 0, y = 0;

        while (n--) {
            char d; 
            int s;
            cin >> d >> s;

            if (d == 'u') {
                ry += s;
                y = min(l - 1, y + s);
            } else if (d == 'd') {
                ry -= s;
                y = max(0, y - s);
            } else if (d == 'l') {
                rx -= s;
                x = max(0, x - s);
            } else {
                rx += s;
                x = min(w - 1, x + s);
            }
        }

        printf("Robot thinks %d %d\n", rx, ry);
        printf("Actually at %d %d\n\n", x, y);
    }

}
