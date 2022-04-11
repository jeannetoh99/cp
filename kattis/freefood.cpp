#include <bits/stdc++.h>
using namespace std;

int main() {
    int days[366] = {0};
    int n; cin >> n;
    while (n--) {
        int s,t; cin>>s>>t;
        for (int i=s; i<=t; i++) {
            days[i] = 1;
        }
    }
    int c = 0;
    for (int i=1; i<=365; i++) {
        c += days[i];
    }
    cout << c << endl;
}