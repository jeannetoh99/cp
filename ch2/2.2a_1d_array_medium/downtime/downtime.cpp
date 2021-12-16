#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n, k; cin >> n >> k;

    int timestamp[101001] = {0};

    while (n--) {
        int t; cin >> t;
        timestamp[t]++;
        timestamp[t+1000]--;
    }

    int maxLoad = 0;
    int currLoad = 0;
    for (int i = 0; i < 101001; i++) {
        currLoad += timestamp[i];
        maxLoad = max(maxLoad, currLoad);
    }

    cout << ceil((double)maxLoad/k) << endl;

}
