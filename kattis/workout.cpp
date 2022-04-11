#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
#include <unordered_map>

#define ll long long

using namespace std;

int main() {
    ll ju[10];
    ll jr[10];
    for (int i = 0; i < 10; i++) {
        cin >> ju[i] >> jr[i];
    }
    ll u[10];
    ll r[10];
    ll t[10];
    for (int i = 0; i < 10; i++) {
        cin >> u[i] >> r[i] >> t[i];
    }
    ll tt = 0;
    // for 3 rounds
    for (int i = 0; i < 3; i++) {
        // for each machine
        for (int j = 0; j < 10; j++) {
            // if both ready at the same time, other person uses first
            if (tt >= t[j]) {
                ll left = (tt - t[j]) % (u[j] + r[j]);
                t[j] = tt - left + u[j] + r[j];
                // Adjust Jim's starting time on this machine
                tt = max(tt, t[j] - r[j]);
            }

            // Jim uses machine
            tt += ju[j];
            // Adjust other person's starting time on their machine
            t[j] = max(t[j], tt);
            // Add recovery time to Jim's total time
            tt += jr[j];
        }
    }
    // Minus Jim's last recovery time
    cout << tt - jr[9] << endl;
}