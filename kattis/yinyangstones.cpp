#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    char c;
    int w = 0;
    int b = 0;

    while(scanf("%c", &c) && c != '\n') {
        if (c == 'W') {
            w++;
        } else {
            b++;
        }
    }

    cout << (w == b) << endl;
}
