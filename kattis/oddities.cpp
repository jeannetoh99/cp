#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    int N; cin >> N;

    while (N--) {

        int x; cin >> x;

        if (x % 2 == 0) {
            printf("%d is even\n", x);
        } else {
            printf("%d is odd\n", x);
        }

    }
    return 0;
}