#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void swap(int nums[5], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int main() {
    int nums[5];
    for (int i=0;i<5;i++) cin>>nums[i];
    int seq = 0;
    while (true) {
        if (nums[seq]<=nums[seq+1]) {
            seq = (seq + 1) % 4;
            continue;
        }
        swap(nums, seq, seq+1);
        bool sorted = true;
        for (int i=0; i<5; i++) {
            if (i!=0) cout << " ";
            cout << nums[i];
            if (nums[i] != i+1) sorted = false;
        }
        cout << "\n";
        if (sorted) break;
        seq = (seq + 1) % 4;
    }
}
