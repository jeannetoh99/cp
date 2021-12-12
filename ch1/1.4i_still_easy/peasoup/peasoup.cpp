#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int n; scanf("%d\n", &n);
    while (n--) {
        int m; scanf("%d\n", &m);
        string name; getline(cin, name);
        bool hasPS = false;
        bool hasPC = false;
        while (m--) {
            string f; getline(cin, f);
            if (f == "pea soup") {
                hasPS = true;
            }
            if (f == "pancakes") {
                hasPC = true;
            }
        }
        if (hasPS && hasPC) {
            cout << name << endl;
            return 0;
        }
    }
    cout << "Anywhere is fine I guess" << endl;
    return 0;
}
