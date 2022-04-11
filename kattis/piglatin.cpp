#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findFirstVowel(string word) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    int pos = word.size();
    for (char v : vowels) {
        int p = word.find(v);
        if (p != -1 && p < pos) pos = p;
    }
    return pos;
}

int main() {

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        bool first = true;
        while (ss >> word) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            if (vowels.find(word.at(0)) == vowels.end()) {
                int p = findFirstVowel(word);
                string newWord = word.substr(p) + word.substr(0, p) + "ay";
                cout << newWord;
            } else {
                cout << word << "yay";
            }
        }
        cout << endl;
    }

}
