#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

// Takes x_1 as input
void solve(int number) {
    string ns = to_string(number);
    string prev = ns;

    int i = 2;
    while (true) {
        string ns = to_string(prev.size());
        if (ns == prev) {
            cout << i << endl;
            return;
        }
        prev = ns;
        i++;
    }
}

int main() {

    string line;

    while (true) {
        getline(cin, line);

        if (line == "END") {
            break;
        } else if (line == "1") {
            cout << 1 << endl;
        } else {
            solve(line.size());
        }
    }

    return 0;
}