#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    int arr[n];
    int prefixmax[n];
    int postfixmin[n];

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = x;
        if (i == 0) prefixmax[i] = x;
        else prefixmax[i] = max(prefixmax[i-1], x);
    }

    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) postfixmin[i] = arr[i];
        else postfixmin[i] = min(postfixmin[i+1], arr[i]);
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        if ((i == 0 && postfixmin[i+1] > arr[i])
            || (i == n-1 && prefixmax[i-1] <= arr[i])
            || (i > 0 && i < n-1 && prefixmax[i-1] <= arr[i] && postfixmin[i+1] > arr[i])
        ) res++;
    }

    cout << res << endl;
}
