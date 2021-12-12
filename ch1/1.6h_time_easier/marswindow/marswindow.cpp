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
    int y; cin >> y;

    int b = 2017 * 12 + 4;
    int m = y * 12;

    string ans = (m - b) % 26 < 12 ? "yes" : "no";

    cout << ans << endl;
}
