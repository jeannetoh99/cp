#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int p0, p1, p2, p3;
    
    while(scanf("%d %d %d %d\n", &p0, &p1, &p2, &p3) && (p0 || p1 || p2 || p3)) {
        // turn the dial clockwise 2 full turns, end at p0
        int ticks = 80;
        // turn clockwise from p0 to p1
        ticks += p1 > p0 ? 40 - (p1 - p0) : p0 - p1;
        // turn the dial counter-clockwise 1 full turn, end at p1
        ticks += 40;
        // continue turning counter-clockwise until the 2nd number is reached
        ticks += p2 >= p1 ? p2 - p1 : 40 - (p1 - p2);
        // turn the dial clockwise again until the 3rd number is reached
        ticks += p3 > p2 ? 40 - (p3 - p2) : p2 - p3;

        cout << ticks * 9 << endl;
    }
}
