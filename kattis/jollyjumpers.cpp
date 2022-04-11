#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n;

    while (cin >> n) {
        unordered_set<int> diff;
        int p; cin >> p;
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            int c; cin >> c;
            if (!jolly) continue;
            int d = abs(c-p);
            if (diff.find(d) != diff.end() || d >= n) jolly = false;
            diff.insert(d);
            p = c;
        }
        if (jolly) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }

}
