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
    int C, n; cin >> C >> n;

    int x = 0;

    while (n--) {
        int l, e, s; cin >> l >> e >> s;
        
        x -= l;
        if (x < 0) {
            printf("impossible\n");
            return 0;
        }

        x += e;
        if (x > C || (x < C && s > 0)) {
            printf("impossible\n");
            return 0;
        }
    }

    if (x != 0) {
        printf("impossible\n");
    } else {
        printf("possible\n");
    }

    return 0;
}