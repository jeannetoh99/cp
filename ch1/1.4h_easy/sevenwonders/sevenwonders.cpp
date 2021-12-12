#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int t=0, c=0, g=0;
    char ch;

    while(scanf("%c", &ch) && ch != '\n') {
        if (ch == 'T') t++;
        if (ch == 'C') c++;
        if (ch == 'G') g++;
    }

    cout << t*t + c*c + g*g + 7*min(t,min(c,g)) << endl;
}
