#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n;
    bool first = true;
    while (cin >> n && n) {
        if (first) first = false; else cout << endl;
        int one = 0, two = 0;
        while (n--) {
            string cmd; int m; cin >> cmd >> m;
            if (cmd == "DROP") {
                two += m;
                cout << "DROP 2 " << m << endl;
            } else if (cmd == "TAKE") {
                if (m <= one) {
                    one -= m;
                    cout << "TAKE 1 " << m << endl;
                } else {
                    m -= one;
                    if (one > 0) cout << "TAKE 1 " << one << endl;
                    one = two;
                    cout << "MOVE 2->1 " << two << endl; 
                    two = 0;
                    cout << "TAKE 1 " << m << endl;
                    one -= m;
                }
            }
        }
    }

}
