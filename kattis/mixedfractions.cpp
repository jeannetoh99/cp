#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n, d; 

    while(cin >> n >> d && (n || d)) {
        int q = n / d;
        int r = n % d;
        cout << q << " " << r << " / " << d << "\n";
    }

}
