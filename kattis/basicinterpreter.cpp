#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

map<int, string> statements;
unordered_map<string, int> vars;
string ig;

int getValue(string x) {
    if (vars.find(x) == vars.end()) return stoi(x);
    else return vars[x];
}

void let(stringstream &ss) {
    string var, a, op, b;
    ss >> var >> ig >> a;
    if (ss >> op >> b) {
        int x = getValue(a), y = getValue(b), res;
        if (op == "+") res = x + y;
        else if (op == "-") res = x - y;
        else if (op == "*") res = x * y;
        else res = x / y;
        vars[var] = res;
    } else {
        vars[var] = getValue(a);
    }
}

map<int, string>::iterator ifthen(stringstream &ss, map<int, string>::iterator it) {
    string a, cmp, b; int l;
    ss >> a >> cmp >> b >> ig >> ig >> l;
    int x = getValue(a), y = getValue(b);
    bool condition;
    if (cmp == "=") condition = x == y;
    else if (cmp == ">") condition = x > y;
    else if (cmp == "<") condition = x < y;
    else if (cmp == "<>") condition = x != y;
    else if (cmp == "<=") condition = x <= y;
    else if (cmp == ">=") condition = x >= y;

    if (condition) return statements.find(l);
    else return next(it);
}

int main() {
    int l;
    while (cin >> l) {
        string statement; getline(cin, statement);
        statement.erase(0,1);
        statements[l] = statement;
    }

    auto it = statements.begin();
    while (it != statements.end()) {
        stringstream ss((*it).second);
        string cmd; ss >> cmd;
        if (cmd == "LET") {
            let(ss);
            it++;
        } else if (cmd == "IF") {
            it = ifthen(ss, it);
        } else {
            string s; getline(ss, s); 
            s = s.substr(1, s.length() - 1);
            s = (vars.find(s) == vars.end()) ? s.substr(1, s.length() - 2) : to_string(vars[s]);
            cout << s;
            if (cmd == "PRINTLN") cout << "\n";
            it++;
        }
    }
}
