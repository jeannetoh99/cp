#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>

#define ll long long

using namespace std;

int main() {

    int T; cin >> T;
    while (T--) {
        double R, B, M;
        cin >> R >> B >> M;

        // monthly interest rate in decimal
        R /= 100;

        for (int i = 1; i <= 1200; i++) {

            double r = round(B * R * 100) / 100;

            // find interest rate
            B += r;
            B = round(B * 100) / 100;

            // make payment
            B -= M;

            if (B <= 0) {
                cout << i << endl;
                break;
            }
        }

        if (B > 0) cout << "impossible" << endl;
    }

}
