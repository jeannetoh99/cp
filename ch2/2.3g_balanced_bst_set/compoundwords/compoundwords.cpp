#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string word; vector<string> words;
    while (cin >> word) {
        words.push_back(word);
    }

    set<string> compound;

    for (int i=0; i<words.size(); i++) {
        for (int j=0; j<words.size(); j++) {
            if (i==j) continue;
            compound.insert(words[i] + words[j]);
        }
    }

    for (string w : compound) {
        cout << w << "\n";
    }
}
