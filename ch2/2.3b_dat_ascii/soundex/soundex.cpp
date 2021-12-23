#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    unordered_map<char, int> mapping;
    for (char c : "AEIOUHWY") mapping[c] = 0;
    for (char c : "BFPV") mapping[c] = 1;
    for (char c : "CGJKQSXZ") mapping[c] = 2;
    for (char c : "DT") mapping[c] = 3;
    for (char c : "L" ) mapping[c] = 4;
    for (char c : "MN") mapping[c] = 5;
    for (char c : "R") mapping[c] = 6;

    string s; 
    while (cin >> s) {
        string ans; int p;
        for (int i=0; i<s.size(); i++) {
            if (mapping[s[i]] == 0) continue;
            if (i!=0 && mapping[s[i]] == mapping[s[i-1]]) continue;
            ans += ('0' + mapping[s[i]]);
        }
        cout << ans << "\n";
    }
}
