#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {

    int time[26] = {0};
    int penalty[26] = {0};

    int t;
    char p;
    string r;

    while (true) {

        cin >> t;
        if (t == -1) break;
        cin >> p >> r;

        if (time[p - 'A'] != 0) continue;

        if (r == "right") {
            time[p-'A'] = t;
        } else if (r == "wrong") {
            penalty[p-'A'] += 20;
        } 
    }

    int s = 0;
    int c = 0;

    for (int i = 0; i < 26; i++) {
        if (time[i] == 0) continue;
        c++;
        s += time[i] + penalty[i];
    }

    cout << c << " " << s << endl;
}