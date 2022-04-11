#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int getPoints (int a, int b) {
    if (a > b) {
        return a*10+b;
    } else {
        return b*10+a;
    }
}

int getWinner(int s, int r) {

    if (s == r) {
        return 0;
    } else if (s == 21) {
        return 1;
    } else if (r == 21) {
        return 2;
    } else if (s % 11 == 0 && r % 11 != 0) {
        return 1;
    } else if (s % 11 != 0 && r % 11 == 0) {
        return 2;
    } else if (s > r) {
        return 1;
    } else {
        return 2;
    }

}


int main() {

    int s0, s1, r0, r1;

    while (true) {
        cin >> s0 >> s1 >> r0 >> r1;
        if (!s0 && !s1 && !r0 && !r1) break;

        int s = getPoints(s0, s1);
        int r = getPoints(r0, r1);

        int w = getWinner(s, r);

        if (w == 0) {
            cout << "Tie." << endl;
        } else {
            printf("Player %d wins.\n", w);
        }
    }
}