#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

bool isSet(vector<int> &a, vector<int> &b, vector<int> &c) {
    for (int i=0; i<4; i++) {
        if ((a[i] == b[i] && b[i] == c[i]) ||
            (a[i] != b[i] && b[i] != c[i] && a[i] != c[i])) continue;
        else return false;
    }
    return true;
}

int main() {
    vector<vector<int>> cards;
    for (int i=0; i<12; i++) {
        int a; char b,c,d; cin >> a >> b >> c >> d;
        cards.push_back({a,b,c,d});
    }

    bool hasSets = false;
    for (int i=0; i<12; i++) {
        for (int j=i+1; j<12; j++) {
            for (int k=j+1; k<12; k++) {
                if (isSet(cards[i], cards[j], cards[k])) {
                    hasSets = true;
                    printf("%d %d %d\n", i+1, j+1, k+1);
                }
            }
        }
    }
    if (!hasSets) printf("no sets\n");
}
