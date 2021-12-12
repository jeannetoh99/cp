#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;

    double ans = 0;

    while (N--) {
        double q, y;
        cin >> q >> y;
        ans += (q*y);
    } 

    printf("%.3f\n", ans);
    return 0;
}