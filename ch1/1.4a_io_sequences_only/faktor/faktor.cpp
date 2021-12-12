#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int A;
    float I;
    scanf("%d %f", &A, &I);
    printf("%d\n", (int) ceil((I - 0.99) * A));
    return 0;
}