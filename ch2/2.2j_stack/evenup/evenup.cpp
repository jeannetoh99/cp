#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    stack<int> s;

    int n; cin >> n;

    while (n--) {
        int x; cin >> x;
        if (s.empty() || (s.top() + x) % 2 == 1) {
            s.push(x);
        } else {
            s.pop();
        }
    }

    cout << s.size() << endl;

}
