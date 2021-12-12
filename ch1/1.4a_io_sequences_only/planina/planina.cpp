#include <iostream>
using namespace std;

int main() {

    int i, p = 0;

    scanf("%d", &i);
    while (i--) {
        p += p + 1;
    }
    p += 2;

    printf("%d\n", p*p);

    return 0;
}