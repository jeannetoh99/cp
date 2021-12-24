#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    unordered_set<string> history;
    string prev;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        if (history.empty()) {
            history.insert(s);
        } else {
            if (prev.back() != s.front() || history.find(s) != history.end()) {
                int player = (i % 2) + 1;
                printf("Player %d lost\n", player);
                return 0;
            }
            history.insert(s);
        }
        prev = s;
    }
    printf("Fair Game\n");
}
