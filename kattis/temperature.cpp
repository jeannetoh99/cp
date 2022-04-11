#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    double X, Y;

    cin >> X >> Y;

    if (X == 0 && Y == 1) {
        printf("ALL GOOD\n");
    } else if (Y == 1) {
        printf("IMPOSSIBLE\n");
    } else {
        cout << fixed << setprecision(9) << (X / (1.0-Y)) << endl;
    }

}