#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    int arr[n];
    memset(arr, 0, sizeof(int)*n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x; cin >> x;
            arr[i] |= x;
            arr[j] |= x;
        }
    }

    for (int i=0; i<n; i++) {
        if (i != 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}
