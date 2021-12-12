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

    ll T; cin >> T;

    while (T--) {
        ll D, M; cin >> D >> M;
        ll ans = 0;
        ll first = 6;

        for (int i = 0; i < M; i++) {
            ll days; cin >> days;
            // if first day of month is sunday, 13th is friday
            // there must be at least 13 days that month
            if (first == 6 && days >= 13) ans++;
            first = (first + days) % 7;
        }

        cout << ans << endl;
    }

}
