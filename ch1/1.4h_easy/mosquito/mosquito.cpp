#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int m,p,l,e,r,s,n;

    while(scanf("%d %d %d %d %d %d %d\n", &m, &p, &l, &e, &r, &s, &n) != EOF) {
        while (n--) {
            int newM = p / s;
            p = l / r;
            l = m * e;
            m = newM;
        }

        cout << m << endl;
    }

}
