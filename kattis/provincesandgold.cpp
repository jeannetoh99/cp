#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int G,S,C;
    cin >> G >> S >> C;

    int b = 3*G + 2*S + 1*C;

    if (b >= 8) {
        cout << "Province or Gold\n";
    } else if (b >= 6) {
        cout << "Duchy or Gold\n";
    } else if (b >= 5) {
        cout << "Duchy or Silver\n";
    } else if (b >= 3) {
        cout << "Estate or Silver\n";
    } else if (b >= 2) {
        cout << "Estate or Copper\n";
    } else {
        cout << "Copper\n";
    }

    return 0;
}