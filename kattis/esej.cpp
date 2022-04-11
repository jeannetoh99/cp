#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int a,b; cin>>a>>b;
    bool first = true;
    int minWords = max(a, (int) ceil(b/2));
    for (int i=0; i<minWords; i++) {
        if (first) first = false; else cout << " ";
        string word = to_string(i);
        for (char c : word) {
            cout << (char) ('a' + c - '0');
        }
    }
    cout << endl;

}
