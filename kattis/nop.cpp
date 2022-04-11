#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    char c;

    int prev = 0;
    int total = 0;
    while (scanf("%c", &c) && c != '\n') {
        if (c - 'a' < 0) {
            total +=  (4 - (prev % 4)) % 4;
            prev = 1;
        } else {
            prev++;
        }
    }

    printf("%d\n", total);
}
