#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (s == "mumble") continue;
        int x = stoi(s);
        if (x != i) {
            cout << "something is fishy" << endl;
            return 0;
        }
    }
    cout << "makes sense\n";
}
