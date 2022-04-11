#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int N; cin >> N;
    double n = 0;
    double d = 0;

    while (N--) {
        double c; cin >> c;
        if (c == -1) continue;
        n += c;
        d++;
    }

    cout << fixed << setprecision(9) << n / d << endl;
}