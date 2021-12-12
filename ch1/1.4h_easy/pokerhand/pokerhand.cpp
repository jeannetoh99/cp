#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int rankToIndex(char rank) {
    switch (rank) {
        case 'A':
            return 0;
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12;
        default:
            return rank - '1';
    }
}

int main() {

    int ranks[13] = {0};
    int strength = 0;

    for (int i = 0; i < 5; i++) {
        char r, s; cin >> r >> s;
        int in = rankToIndex(r);

        ranks[in]++;
        if (ranks[in] > strength) strength = ranks[in];
    }

    cout << strength << endl;
}
