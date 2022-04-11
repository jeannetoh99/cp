#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    int UPPER = 20;
    bool isPrime[UPPER+1]; memset(isPrime, true, sizeof(bool)*(UPPER+1));
    unordered_set<int> primeMinusOne;
    vector<int> bob = {3};

    int p = 2;
    while (p <= UPPER) {
        cout << p << endl;
        int c = p+p;
        while (c <= UPPER) {
            isPrime[c] = false;
            c+=p;
        }
        p++; while (p <= UPPER && !isPrime[p]) p++;
    }

    for (int i=2; i<=UPPER; i++) if (isPrime[i]) primeMinusOne.insert(i-1);
    
    for (int i=4; i<= UPPER; i++) {
        vector<int> temp = bob;
        bool bobWins = true;
        for (int b : temp) {
            if (i < b) continue;
            if (primeMinusOne.find(i-b) != primeMinusOne.end()) {
                bobWins = false; break;
            }
        }
        if (bobWins) bob.push_back(i);
    }

    for (int b : bob) {
        cout << b << ",";
    }

    // int q; cin >> q;
    // while (q--) {
    //     int n; cin >> n;
    //     if (bob.find(n) == bob.end()) cout << "Alice\n";
    //     else cout << "Bob\n";
    // }

}
