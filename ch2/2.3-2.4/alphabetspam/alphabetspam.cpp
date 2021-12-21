#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string str; cin >> str;

    double w = 0; // '_' : 95
    double l = 0; // 'a'-'z': 97-122
    double u = 0; // 'A'-'Z': 65-90
    double s = 0; // everything else
    
    for (char c : str) {
        if (c == '_') {
            w++;
        } else if (c - 'a' >= 0 && c - 'a' < 26) {
            l++;
        } else if (c - 'A' >= 0 && c - 'A' < 26) {
            u++;
        } else {
            s++;
        }
    }

    double t = w+l+u+s;

    cout << w/t << endl;
    cout << l/t << endl;
    cout << u/t << endl;
    cout << s/t << endl;

}
