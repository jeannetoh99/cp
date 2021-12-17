#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int mergesort(int curr[], int pos[], int start, int end) {
    if (start >= end) return 0;

    int mid = start + (end - start) / 2;

    int res = mergesort(curr, pos, start, mid) + mergesort(curr, pos, mid+1, end);

    int temp[end-start+1];
    int p0 = start;
    int p1 = mid+1;
    int i = 0;

    while (p0 <= mid && p1 <= end) {
        if (pos[curr[p0]-1] < pos[curr[p1]-1]) {
            temp[i++] = curr[p0++];
        } else {
            res += (mid - p0 + 1);
            temp[i++] = curr[p1++];
        }
    }

    while (p0 <= mid) temp[i++] = curr[p0++];
    while (p1 <= end) temp[i++] = curr[p1++];

    for (int i=start; i<=end; i++) {
        curr[i] = temp[i-start];
    }

    return res;
}

int main() {

    int n; cin >> n;

    int curr[n];
    int want[n];
    int pos[n];

    for (int i = 0; i < n; i++) cin >> curr[i];
    for (int i = 0; i < n; i++) cin >> want[i];
    for (int i = 0; i < n; i++) pos[want[i]-1] = i;

    int res = mergesort(curr, pos, 0, n-1);

    if (res % 2 == 0) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }

}
