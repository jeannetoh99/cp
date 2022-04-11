#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X, N;

    cin >> X >> N;

    int r = 0;

    while (N--) {
        int P; cin >> P;
        r += (X-P);
    }

    cout << r + X << '\n';

    return 0;
}