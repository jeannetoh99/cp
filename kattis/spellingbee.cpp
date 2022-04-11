#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    unordered_set<char> letters;
    char center;

    for (int i = 0; i < 7; i++) {
        char c; cin >> c;
        letters.insert(c);
        if (i == 0) center = c;
    }

    int n; cin >> n;
    while (n--) {
        string word; cin >> word;
        bool hasCenter = false;
        bool valid = true;

        if (word.size() < 4) continue;

        for (char c : word) {
            if (letters.find(c) == letters.end()) valid = false;
            if (c == center) hasCenter = true;
        }

        if (valid && hasCenter) cout << word << endl;
    }

}
