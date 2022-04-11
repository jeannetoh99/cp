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

    int d;
    string p;
    string c;

    for (int i = 0; i < N; i++) {
        cin >> c;

        if (i == 0) {
            p = c;
        } else if (i == 1) {
            d = p.compare(c);
            p = c;
        } else {
            if (d * p.compare(c) > 0) {
                continue;
            } else {
                cout << "NEITHER" << endl;
                return 0;
            }
        }
    }

    if (d < 0) {
        cout << "INCREASING" << endl;
    } else {
        cout << "DECREASING" << endl;
    }

    return 0;
}
