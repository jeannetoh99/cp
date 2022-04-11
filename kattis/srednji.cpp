#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n,b; cin>>n>>b;
    int B[n];

    int idx = 0;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        B[i] = a;
        if (a == b) idx = i;
    }

    unordered_map<int, int> leftDiff;
    unordered_map<int, int> rightDiff;

    int d = 0; leftDiff.insert({0, 1});
    for (int i=idx-1; i>=0; i--) {
        if (B[i] < b) d--; else d++;
        if (leftDiff.find(d) == leftDiff.end()) leftDiff[d] = 0;
        leftDiff[d]++;
    }
    d = 0; rightDiff.insert({0, 1});
    for (int i=idx+1; i<n; i++) {
        if (B[i] < b) d--; else d++;
        if (rightDiff.find(d) == rightDiff.end()) rightDiff[d] = 0;
        rightDiff[d]++;
    }

    int c = 0;
    for (ii l : leftDiff) {
        int k = l.first;
        if (rightDiff.find(-k) != rightDiff.end()) {
            c += leftDiff[k]*rightDiff[-k];
        }
    }

    cout << c << "\n";
}

