#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int, int> seats; // (language, last seat no)
    int awkwardness = n;

    for (int i=0; i<n; i++) {
        int lang; cin >> lang;
        if (seats.find(lang) != seats.end()) {
            int l = i - seats[lang];
            awkwardness= min(awkwardness, l);
        }
        seats[lang] = i;
    }

    cout << awkwardness << endl;
}
