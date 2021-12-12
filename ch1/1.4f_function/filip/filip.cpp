#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int flip(int num) {

    int ones = num % 10;
    int tens = ((num % 100) - (num % 10)) / 10;
    int hundreds = (num - (num % 100)) / 100;

    return hundreds + 10 * tens + 100 * ones;
}

int main() {

    int a,b;

    cin >> a >> b;

    int c = flip(a);
    int d = flip(b);

    if (c > d) {
        cout << c << endl;
    } else {
        cout << d << endl;
    }
}