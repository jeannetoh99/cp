#include <stdio.h>
using namespace std;

int main() {
    int a,b,c,n;
    if (scanf("%d %d %d %d", &a, &b, &c, &n) == 4) {
        printf(a >= 1 && b >=1 && c >= 1 && n >= 3 && a+b+c >= n ? "YES\n" : "NO\n");
    }
}