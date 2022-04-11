#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int mergesort(int line[20], int start, int end) {

    if (start >= end) return 0;

    int mid = start + (end - start) / 2;
    int res = mergesort(line, start, mid) + mergesort(line, mid + 1, end);
    int temp[end-start+1];

    int p0 = start;
    int p1 = mid + 1;
    int i = 0;

    while (p0 <= mid && p1 <= end) {
        if (line[p0] <= line[p1]) {
            temp[i++] = line[p0++]; 
        } else {
            res += mid - p0 + 1;
            temp[i++] = line[p1++];
        }
    }
    while (p0 <= mid) {
        temp[i++] = line[p0++];
    }
    while (p1 <= end) {
        temp[i++] = line[p1++];
    }
    
    for (int j=start; j<=end; j++) {
        line[j] = temp[j-start];
    }

    return res;
}

// count inversions
int solve(int line[20]) {
    return mergesort(line, 0, 19);
}

int main() {
    int p; cin >> p;
    while (p--) {
        int k; cin >> k;
        int line[20];
        for (int i=0; i<20; i++) cin >> line[i];
        cout << k << " " << solve(line) << endl;
    }
}
