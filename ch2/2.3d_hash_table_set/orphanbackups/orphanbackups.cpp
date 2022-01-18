#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string f;
    set<string> indexed;
    while (getline(cin, f) && f != "") {
        indexed.insert(f);
    }
    
    multimap<string,string> backups;
    while (getline(cin, f)) {
        string c = f.substr(0,f.find_last_of('_'));
        c = c.substr(0,c.find_last_of('_'));
        backups.insert({c, f});
    }

    bool found = false;
    for (pair<string,string> b : backups) {
        if (!indexed.count(b.first)) { cout << "F " << b.second << "\n"; found = true; }
    }
    for (string i : indexed) {
        if (!backups.count(i)) { cout << "I " << i << "\n"; found = true; }
    }
    if (!found) cout << "No mismatches.\n";
}
