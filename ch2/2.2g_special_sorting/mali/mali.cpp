#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int A[100] = {0};
    int B[100] = {0};

    int n; cin >> n;

    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        A[a-1]++;
        B[b-1]++;

        int AA[100], BB[100];
        copy(begin(A), end(A), begin(AA));
        copy(begin(B), end(B), begin(BB));

        int pa=0;
        int pb=99;
        int maxSum = 0;

        while (true) {
            while (AA[pa] == 0) pa++;
            while (BB[pb] == 0) pb--;
            if (pa > 99 || pb < 0) break;
            // printf("A%d: %d, B%d: %d\n", pa+1, AA[pa], pb+1, BB[pb]);
            int val = min(AA[pa], BB[pb]);
            maxSum = max(maxSum, (pa+1) + (pb+1));
            AA[pa] -= val;
            BB[pb] -= val;
        }

        cout << maxSum << endl;
    }

}
