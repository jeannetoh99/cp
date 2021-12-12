#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {

    int c = 1;
    int n;

    while (scanf("%d", &n) != EOF) {
        
        int min = 1e9;
        int max = -1e9;

        while (n--) {
            int i; cin >> i;
            if (i < min) min = i;
            if (i > max) max = i;
        }

        printf("Case %d: %d %d %d\n", c++, min, max, max - min);

    }

    return 0;

}
