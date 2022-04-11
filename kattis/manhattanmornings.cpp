#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

void flip(ii &a, int r, int t, int axis) { // 0: flip along x-axis, 1: flip along y-axis
    if (axis == 0) {
        int d = t - a.second;
        a.second = t + d;
    } else {
        int d = r - a.first;
        a.first = r + d;
    }
}

// int binary_search(vi is, int y) {
//     int lo = 0, hi=is.size();
//     while (lo < hi) {
//         int mid = lo + (hi-lo) / 2;
//         if (is[mid] <= y) lo = mid + 1;
//         else hi = mid;
//     }
//     return lo;
// }

int lis(vii errands, ii s, ii t, int n) {
    vi is;
    is.push_back(-1); // y, number of errands (length of lis) is represented by index of is

    for (int i=0; i<n; i++) {
        int x = errands[i].first;
        int y = errands[i].second;
        if (x < s.first || y < s.second || y > t.second) continue;
        if (x > t.first) break;
        
        auto it = upper_bound(is.begin(), is.end(), y);
        int idx = it - is.begin();
        if (idx == is.size()) {
            is.push_back(y);
        } else {
            is[idx] = y;
        }
    }
   return is.size() - 1;
}

int main() {
    int n; cin >> n;
    ii s, t;
    cin>>s.first>>s.second>>t.first>>t.second;
    int right = max(s.first, t.first);
    int top = max(s.second, t.second);

    bool flipX, flipY;
    flipY = s.first > t.first;
    flipX = s.second > t.second;
    if (flipX) flip(s, right, top, 0), flip(t, right, top, 0);
    if (flipY) flip(s, right, top, 1), flip(t, right, top, 1);

    vii errands;
    for (int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        errands.push_back({x,y});
        if (flipX) flip(errands[i], right, top, 0);
        if (flipY) flip(errands[i], right, top, 1);
    }
    sort(errands.begin(), errands.end()); // sort by x

    cout << lis(errands, s, t, n) << endl;
}
