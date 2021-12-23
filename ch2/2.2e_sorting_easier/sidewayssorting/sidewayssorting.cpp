#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

bool compare(vector<char> A, vector<char> B) {
    if (B.size() < A.size()) swap(A, B);
    for (int i=0; i<A.size(); i++) {
        int a = A.at(i) >= 'a' ? A.at(i) - 'a' : A.at(i) - 'A';
        int b = B.at(i) >= 'a' ? B.at(i) - 'a' : B.at(i) - 'A';
        if (a < b) return true;
        if (a > b) return false;
    }
    return false;
}

int main() {
    int r, c;
    bool first = true;
    while (cin>>r>>c && (r || c)) {
        if (first) {
            first = false;
        } else {
            cout << endl;
        }
        vector<vector<char>> block(c, vector<char>(r, '0'));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> block[j][i];
            }
        }
        stable_sort(block.begin(), block.end(), compare);
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << block[j][i];
            }
            cout << endl;
        }
    }
}
