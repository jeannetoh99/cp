#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {

    int n; cin >> n;

    int min = INFINITY;
    int day = -1;


    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t < min) {
            min = t;
            day = i;
        }
    }

    cout << day << endl;

}
