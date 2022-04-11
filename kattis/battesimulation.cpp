#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

char getMove(char c) {
    if (c == 'R') {
        return 'S';
    } else if (c == 'B') {
        return 'K';
    } else {
        return 'H';
    }
}

int main() {

    string M; getline(cin, M);

    int cc = 0; // combo count
    int move[26] = {0};
    int i = 0;
    int j = 0;

    while (i < M.size()) {
        // cout << cc << endl;
        // cout << "R: " << move['R'-'A'] << endl;
        // cout << "B: " << move['B'-'A'] << endl;
        // cout << "L: " << move['L'-'A'] << endl;
        if (j-i == 3 || j == M.size()) {
            if (cc == 3) {
                cout << 'C';
                cc = 0;
                memset(move, 0, sizeof(move));
                i+=3;
            } else {
                char m = M.at(i);
                cout << getMove(m);
                move[m - 'A']--;
                if (move[m - 'A'] == 0) cc--;
                i++;
            }
        }
        if (j < M.size()) {
            char c = M.at(j);
            move[c-'A']++;
            if (move[c-'A'] == 1) cc++;
            j++;
        }
    }
    cout << endl;
}

