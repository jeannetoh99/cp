#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

string solutions[13] = {
    "1\n",
    "2 1\n",
    "3 1 2\n",
    "2 1 4 3\n",
    "3 1 4 5 2\n",
    "4 1 6 3 2 5\n",
    "5 1 3 4 2 6 7\n",
    "3 1 7 5 2 6 8 4\n",
    "7 1 8 6 2 9 4 5 3\n",
    "9 1 8 5 2 4 7 6 3 10\n",
    "5 1 6 4 2 10 11 7 3 8 9\n",
    "7 1 4 9 2 11 10 8 3 6 5 12\n",
    "4 1 13 11 2 10 6 7 3 5 12 9 8\n"
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        cout << solutions[n-1];
    }
}
