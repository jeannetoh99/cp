#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int C; cin >> C;

    for (int c=1; c<=C; c++) {
        string S, T; cin >> S >> T;

        int s0 = 0;
        int s1 = 0;
        int t0 = 0; // number of 0s needed
        int t1 = 0; // number of 1s needed
        int sq = 0; // number of question marks in S;

        for (int i = 0; i < S.size(); i++) {
            char s = S.at(i);
            char t = T.at(i);
            if (s == t) continue;
            if (s == '?') {
                sq++;
            } else if (s == '0') {
                s0++;
            } else {
                s1++;
            }
            if (t == '0') {
                t0++;
            } else {
                t1++;
            }
        }

        if (sq + s0 < t0) {
            printf("Case %d: %d\n", c, -1);
        } else {
            printf("Case %d: %d\n", c, max(s0, s1) + sq);
        }
    }

}
