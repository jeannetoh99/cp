#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        double tot = 0;
        vector<double> grades(n, 0);
        for (int i=0; i<n; i++) {
            cin >> grades[i];
            tot += grades[i];
        }
        double avg = tot/n; double d = 0;
        for (int i=0; i<n; i++) {
            if (grades[i]>avg) d++;
        }
        cout << fixed << setprecision(3) << d/n*100 << "%\n";
    }
}