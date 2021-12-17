#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n;

    while (cin >> n, n) {

        int num[32];
        memset(num, -1, sizeof(int) * 32);
        while (n--) {
            string inst; 
            cin >> inst;

            if (inst == "SET") {
                int i; cin >> i;
                num[i] = 1;
            } else if (inst == "CLEAR") {
                int i; cin >> i;
                num[i] = 0;
            } else if (inst == "AND") {
                int i, j; cin >> i >> j;
                if (num[i] == 0 || num[j] == 0) {
                    num[i] = 0;
                } else if (num[j] == -1) {
                    num[i] = -1;
                }
            } else {
                int i, j; cin >> i >> j;
                if (num[j] == 1) {
                    num[i] = 1;
                } else if (num[i] == 0 && num[j] == -1) {
                    num[i] = -1;
                }
            }
        }

        for (int i=31; i>=0; i--) {
            if (num[i] == -1) cout << "?";
            else cout << num[i];
        }
        cout << endl;

    }

}
