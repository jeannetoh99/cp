#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n,p,m; cin>>n>>p>>m;
    
    unordered_map<string, int> s;

    while (n--) {
        string name; cin >> name;
        s.insert({name, 0});
    }

    bool hasWinner = false;
    while (m--) {
        string name;
        int pts; 
        cin >> name >> pts;
        int b = s[name];
        s[name] += pts;
        if (b < p && s[name] >= p) {
            hasWinner = true;
            cout << name << " wins!\n";
        }
    }

    if (!hasWinner) cout << "No winner!\n";
}
