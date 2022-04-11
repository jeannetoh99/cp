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

    int n; cin >> n;

    while (n--) {
        int s, d; cin >> s >> d;

        if (s - d < 0 || (s - d) % 2 == 1) {
            printf("impossible\n");
            continue;
        }

        int sm = (s - d) / 2;
        int lg = sm + d;

        printf("%d %d\n", lg, sm);
    }

}
