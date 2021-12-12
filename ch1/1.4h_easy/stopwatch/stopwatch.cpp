#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin>>n;

    if (n % 2 == 1) {
        cout << "still running" << endl; 
    } else {
        int tt = 0;
        n /= 2;
        while (n--) {
            int a, b;
            cin >> a >> b;
            tt += (b - a);
        }
        cout << tt << endl;
    }

}
