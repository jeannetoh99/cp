#include <stdio.h>
#include <math.h>
typedef unsigned long long ull;
using namespace std;

int main() {
    int T;
    ull n;
    int l;
    scanf("%d", &T);

    while (T--) {
        scanf("%llu", &n);
        printf("%d\n", (int) (-1 + sqrt(1 + 8 * n)) / 2);
    }

    return 0;
}