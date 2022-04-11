#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    int n; cin >> n;
    int outcomes[6] = {0};
    int index[6] = {0};
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        outcomes[x-1]++;
        index[x-1] = i;
    }
    for (int r=5; r>=0; r--) {
        if (outcomes[r] != 1) continue;
        cout << index[r] << "\n";
        return 0;
    }
    cout << "none\n";
}
