#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; string s;
    cin >> n >> s;

    while (n--) {
        if (n > 1) {
            printf("%d bottles of %s on the wall, %d bottles of %s.\n"
            "Take one down, pass it around, %d bottles of %s on the wall.\n", n+1, s.c_str(), n+1, s.c_str(), n, s.c_str());
        } else if (n == 1) {
            printf("%d bottles of %s on the wall, %d bottles of %s.\n"
            "Take one down, pass it around, %d bottle of %s on the wall.\n", n+1, s.c_str(), n+1, s.c_str(), n, s.c_str());
        } else {
            printf("%d bottle of %s on the wall, %d bottle of %s.\n"
            "Take it down, pass it around, no more bottles of %s.\n", n+1, s.c_str(), n+1, s.c_str(), s.c_str());
        }
    }

    return 0;
}
