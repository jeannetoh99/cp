#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int p, a, b, c, d;

double price(int k) {
    return (double) p * (sin((a*k)+b) + cos((c*k)+d) + 2.0);
}

int main() {

    int n;
    cin >> p >> a >> b >> c >> d >> n;

    double highest = 0;
    double drop = 0;

    for (int i = 1; i <= n; i++) {
        double pi = price(i);
        if (pi > highest) highest = pi;
        if (drop < highest - pi) {
            drop = highest - pi;
        }
    }

    cout << fixed << setprecision(9) << drop << endl;

}