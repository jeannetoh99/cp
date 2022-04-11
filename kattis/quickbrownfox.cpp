#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    string n; getline(cin, n);
    int N = stoi(n);
    bool letters[26];
    while (N--) {
        memset(letters, 0, sizeof(bool)*26);
        string line; getline(cin, line);
        for (char c : line) {
            if (isupper(c)) letters[c - 'A'] = true;
            if (islower(c)) letters[c - 'a'] = true;
        }
        string missing = "";
        for (int i=0; i<26; i++) {
            if (!letters[i]) missing += ('a' + i);
        }
        if (missing.empty()) {
            cout << "pangram\n";
        } else {
            cout << "missing " << missing << "\n";
        }
    }
}
