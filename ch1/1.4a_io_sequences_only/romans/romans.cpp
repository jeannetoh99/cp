#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x;
    scanf("%lf", &x);
    printf("%d\n", (int) round(x * 1000 * 5280 / 4854));
    return 0;
}