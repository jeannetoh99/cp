#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
#include <unordered_map>

#define ll long long

using namespace std;

int calculateDistance(char a, char b, unordered_map<char, int> row, unordered_map<char, int> col) {

    return abs(row[a] - row[b]) + abs(col[a] - col[b]);

}

int calculateDistance(string a, string b, int dist[26][26]) {
    int d = 0;
    
    for (int i = 0; i < a.size(); i++) {
        d += dist[a.at(i) - 'a'][b.at(i) - 'a'];
    }

    return d;
}

bool compareStrings(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {

    int t; cin >> t;

    // Create mappings
    string keyboard[] = {
        "qwertyuiop", 
        "asdfghjkl",
        "zxcvbnm"
    };

    unordered_map<char, int> row;
    unordered_map<char, int> col;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < keyboard[r].size(); c++) {
            char ch = keyboard[r].at(c);
            row.insert(make_pair(ch, r));
            col.insert(make_pair(ch, c));
        }
    }

    int dist[26][26];

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dist[i][j] = calculateDistance('a' + i, 'a' + j, row, col);
        }
    }

    while (t--) {
        string s;
        int l;
        cin >> s >> l;

        vector<pair<string, int>> S;

        for (int i = 0; i < l; i++) {
            string ss; cin >> ss;
            int d = calculateDistance(ss, s, dist);
            S.push_back(make_pair(ss, d));
        }

        sort(S.begin(), S.end(), compareStrings);

        for (const auto p : S) {
            printf("%s %d\n", p.first.c_str(), p.second);
        }
    }

}
