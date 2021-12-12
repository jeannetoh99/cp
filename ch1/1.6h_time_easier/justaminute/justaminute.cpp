#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
#include <unordered_map>

#define ll long long

using namespace std;

int main() {

    int N; cin >> N;

    double tm = 0;
    double ts = 0;

    while (N--) {
        double m, s; cin >> m >> s;
        tm += m;
        ts += s;
    }

    double sl = ts / (tm * 60);
    if (sl <= 1) {
        cout << "measurement error" << endl;
    } else {
        cout << fixed << setprecision(9) << sl << endl;
    }
}
