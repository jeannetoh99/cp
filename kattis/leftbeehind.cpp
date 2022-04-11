#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int x, y;

    while (scanf("%d %d", &x, &y), (x||y)) {
        if (x + y == 13) {
            printf("Never speak again.\n");
        } else if (x < y) {
            printf("Left beehind.\n");
        } else if (y < x) {
            printf("To the convention.\n");
        } else {
            printf("Undecided.\n");
        }
    }

    return 0;
}