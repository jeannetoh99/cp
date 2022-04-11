#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string N, M; cin >> N >> M;
    int K = M.size() - 1;
    int dp = N.size() - K;

    if (dp <= 0) {
        cout << "0."; 
        while (dp++ < 0) cout << "0";
        int j = 0;
        int lnz;
        for (int l = N.size() - 1; l >= j; l--) {
            if (N.at(l) != '0') {
                lnz = l; break;
            }
        }
        while (j <= lnz) {
            cout << N.at(j++);
        }
        cout << endl;
    } else {
        int j = 0;
        while (dp-- > 0) {
            cout << N.at(j++);
        }
        int lnz;
        for (int l = N.size() - 1; l >= j; l--) {
            if (N.at(l) != '0') {
                lnz = l; break;
            }
        }
        if (j <= lnz) cout << ".";
        while (j <= lnz) {
            cout << N.at(j++);
        }
        cout << endl;
    }
}
