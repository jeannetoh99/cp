#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string command;
    unordered_map<string, int> a;
    unordered_map<int, string> b;

    while (cin >> command) {
        if (command == "def") {
            string w; int x;
            cin >> w >> x;
            if (a.find(w) != a.end()) {
                b.erase(b.find(a[w]));
            }
            a[w] = x;
            b[x] = w;
        } else if (command == "clear") {
            a.clear();
            b.clear();
        } else {
            string statement; getline(cin, statement);
            statement = statement.substr(1);
            stringstream ss(statement);
            string var, op;
            op = "+";
            int total = 0;
            bool unknown = false;
            while (true) {
                ss>>var;
                if (a.find(var) == a.end()) {
                    cout << statement << " unknown\n";
                    break;
                }
                if (op == "+") total += a[var];
                else total -= a[var];
                ss>>op;
                if (op == "=") {
                    if (b.find(total) == b.end()) {
                        cout << statement << " unknown\n";
                    } else {
                        cout << statement << " " << b[total] << endl;
                    }
                    break;
                }
            }

        }
    }

}
