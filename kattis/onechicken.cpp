#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    if (n < m) {
        printf("Dr. Chaz will have %d piece%s of chicken left over!\n", m-n, m-n == 1 ? "" : "s");
    } else {
        printf("Dr. Chaz needs %d more piece%s of chicken!\n", n-m, n-m == 1 ? "" : "s");
    }

    return 0;
}