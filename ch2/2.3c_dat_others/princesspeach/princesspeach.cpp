#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    int n, y; cin >> n >> y;
    int found[n];
    memset(found, 0, sizeof(int)*n);
    while (y--) {
        int k; cin >> k;
        found[k] = 1;
    }
    int c = 0;
    for (int i=0; i<n; i++) {
        if (found[i]) c++;
        else cout << i << endl;
    }
    printf("Mario got %d of the dangerous obstacles.\n", c);
}
