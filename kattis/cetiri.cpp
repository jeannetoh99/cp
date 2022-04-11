#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
    int n[3];

    cin >> n[0] >> n[1] >> n[2];

    sort(n, n + 3);

    int d1 = n[1] - n[0];
    int d2 = n[2] - n[1];

    if (d1 == d2) {
        cout << n[2] + d1 << endl;
    } else if (d1 > d2) {
        cout << n[0] + d2 << endl;
    } else {
        cout << n[1] + d1 << endl;
    }

    return 0;

}