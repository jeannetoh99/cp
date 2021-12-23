#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

bool compare(string A, string B) {
    return A.substr(0,2) < B.substr(0, 2);
}

int main() {
    int n; bool first = true;
    while (cin >> n && n) {
        if (first) first = false; else cout << endl;
        vector<string> names;
        while (n--) {
            string name; cin >> name;
            names.push_back(name);
        }
        stable_sort(names.begin(), names.end(), compare);
        for (string name : names) {
            cout << name << endl;
        }
    }
}
