#include <stdio.h>

int main() {
    int n, k, p, T, i=0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &k, &p);
        printf("Case %d: %d\n", ++i, ((k - 1) + p) % n + 1);
    }
}