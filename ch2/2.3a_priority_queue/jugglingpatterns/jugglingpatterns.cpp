#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;

    while (cin >> s) {
        int n = 0;
        for (char c : s) {
            n += (c - '0');
        }
        if (n % s.length() != 0) {
            printf("%s: invalid # of balls\n", s.c_str());
            continue;
        }
        int balls = n / s.length();
        priority_queue<ii, vector<ii>, greater<ii>> pq;

        bool valid = true;
        int m = n*2;

        for (int t=0; t<m; t++) {
            int to_throw = s.at(t % s.length()) - '0';
            if (to_throw == 0) {
                if (!pq.empty() && pq.top().first == t) {
                    valid = false;
                    break;
                }
            } else {
                if (!pq.empty()) {
                    if (pq.top().first < t) {
                        valid = false;
                        break;
                    } else if (pq.top().first == t) {
                        pq.pop();
                    }
                }
                pq.push({t + to_throw, t});
            }
        }

        if (valid) {
            printf("%s: valid with %d balls\n", s.c_str(), balls);
        } else {
            printf("%s: invalid pattern\n", s.c_str());
        }
    }
}