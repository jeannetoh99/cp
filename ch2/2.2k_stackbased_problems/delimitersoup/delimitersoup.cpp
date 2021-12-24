#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int l; scanf("%d\n", &l);
    stack<char> open;

    for (int i=0; i<l; i++) {
        char c; scanf("%c", &c);
        if (c == ' ') continue;
        if (c == '(' || c == '[' || c == '{') {
            open.push(c);
        } else {
            if (open.empty()) {
                cout << c << " " << i << endl;
                return 0;
            }
            char p = open.top();
            if ((p == '(' && c != ')') || (p == '[' && c != ']') || (p == '{' && c != '}')) {
                cout << c << " " << i << endl;
                return 0;
            }
            open.pop();
        }
    }
    cout << "ok so far\n";

}
