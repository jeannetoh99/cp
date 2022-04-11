#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    bool inputs[n];
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        inputs[i] = c == 'T';
    }

    stack<bool> outputs;

    char v; 
    while (cin >> v) {
        if (v == '*') {
            bool a = outputs.top(); outputs.pop();
            bool b = outputs.top(); outputs.pop();
            outputs.push(a && b);
        } else if (v == '+') {
            bool a = outputs.top(); outputs.pop();
            bool b = outputs.top(); outputs.pop();
            outputs.push(a || b);
        } else if (v == '-') {
            bool a = outputs.top(); outputs.pop();
            outputs.push(!a);
        } else {
            bool val = inputs[v - 'A'];
            outputs.push(val);
        }
    }

    cout << (outputs.top() ? 'T' : 'F') << endl;
}
