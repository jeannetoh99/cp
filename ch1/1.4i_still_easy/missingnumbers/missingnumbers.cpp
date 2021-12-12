#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;

    int i = 1;

    for (int k=0; k<n; k++) {
        int x; cin >> x;

        for (int j=i; j<x; j++) {
            printf("%d\n", j);
        }

        i = x + 1;
    }

    if (i == n + 1) printf("good job\n");
}
