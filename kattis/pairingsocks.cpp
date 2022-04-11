#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    stack<int> pile;

    int m = n*2;

    for (int i=0; i<m; i++) {
        int x; cin >> x;
        if (!pile.empty() && pile.top() == x) {
            pile.pop();
        } else {
            pile.push(x);
        }
    }

    if (pile.empty()) {
        cout << n*2 << endl;
    } else {
        cout << "impossible" << endl;
    }

}
