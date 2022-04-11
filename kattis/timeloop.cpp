#include <stdio.h>

int main() {
    int N, i = 0;
    scanf("%d", &N);
    while (N--) {
        printf("%d Abracadabra\n", ++i);
    }
}