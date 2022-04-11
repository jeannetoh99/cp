#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

int getWinner(int p1, string m1, int p2, string m2) {
    if ((m1 == "rock" && m2 == "scissors") ||
        (m1 == "scissors" && m2 == "paper") ||
        (m1 == "paper" && m2 == "rock")) {
        return p1;
    } else {
        return p2;
    }
}

int main() {

    int n, k;
    bool first = true;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cin >> k;

        if (first) {
            first = false;
        } else {
            cout << endl;
        }

        int wins[n];
        int losses[n];
        memset(wins, 0, sizeof(wins));
        memset(losses, 0, sizeof(losses));

        int games = k * n * (n-1) / 2;

        while (games--) {
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;

            if (m1 == m2) continue;
            int winner = getWinner(p1, m1, p2, m2);
            wins[winner-1]++;
            int loser = winner == p1 ? p2 : p1;
            losses[loser-1]++;
        }

        for (int i = 0; i < n; i++) {
            if (wins[i] + losses[i] == 0) {
                cout << "-" << endl;
            } else {
                cout << fixed << setprecision(3) << (float) wins[i] / (float) (wins[i] + losses[i]) << endl;
            }
        }
    }

}