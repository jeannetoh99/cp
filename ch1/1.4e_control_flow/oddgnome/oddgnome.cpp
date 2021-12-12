#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {

    int n; cin >> n;

    while (n--) {
        int m; cin >> m;
        int prev; cin >> prev;
        int curr;
        bool found = false;
        for (int i = 2; i <= m; i++) {
            cin >> curr;
            if (found) continue;
            if (curr != prev + 1) {
                cout << i << endl;
                found = true;
            }
            prev = curr;
        }
    }

}
