#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        bool hasWinner = true;
        int winner = 0;
        int highest = 0;
        int total = 0;
        for (int i = 1; i<=n; i++) {
            int v; cin >> v;
            if (i != 1 && v == highest) hasWinner = false;
            if (v > highest) {
                winner = i;
                highest = v;
                hasWinner = true;
            }
            total += v;
        }
        if (hasWinner && highest * 2 > total) {
            printf("majority winner %d\n", winner);
        } else if (hasWinner) {
            printf("minority winner %d\n", winner);
        } else {
            printf("no winner\n");
        }
    }
    return 0;
}
