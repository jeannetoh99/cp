#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int T; cin >> T;

    while (T--) {

        int n, m; cin >> n >> m;
        vector<vector<int>> prizes;
        vector<int> value;
        vector<int> stickers;
        for (int i = 0; i < n; i++) {
            vector<int> required;
            int k; cin >> k;
            while (k--) {
                int s; cin >> s;
                required.push_back(s);
            }
            prizes.push_back(required);
            int val; cin >> val;
            value.push_back(val);
        }
        for (int j = 0; j < m; j++) {
            int s; cin >> s;
            stickers.push_back(s);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            vector<int> required = prizes[i];
            int min = 1e9;
            for (int j : required) {
                if (stickers[j - 1] < min) {
                    min = stickers[j - 1];
                }
            }
            total += min * value[i];
        }

        cout << total << endl;
    }

    return 0;
}
