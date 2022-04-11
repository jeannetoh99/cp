#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int n, m;

    while (scanf("%lld %lld", &n, &m) == 2) {
        printf("%lld\n", abs(n-m));
    }
}