#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string x, res; getline(cin, x);
    unordered_set<char> vowels = {'a','e','i','o','u'};
    
    for (int i=0; i<x.size(); i++) {
        res += x[i];
        if (vowels.count(x[i])) i+=2;
    }

    cout << res << "\n";
}
