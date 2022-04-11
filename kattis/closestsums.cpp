#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int findClosestSum(int x, vector<int> &nums) {
    int p = 0, q = nums.size() - 1;
    int res = nums[p] + nums[q];
    while (p < q) {
        int sum = nums[p] + nums[q];
        if (abs(x-sum) < abs(x-res)) res = sum;
        if (sum == x) break;
        else if (sum < x) p++;
        else q--;
    }
    return res;
} 

void solve(int n) {
    vector<int> nums;
    while (n--) {
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int m; cin >> m;
    while (m--) {
        int x; cin >> x;
        int res = findClosestSum(x, nums);
        cout << "Closest sum to " << x << " is " << res << ".\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int t = 1;
    while (cin >> n) {
        cout << "Case " << t++ << ":\n";
        solve(n);
    }
}
