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
    int n; cin >> n;
    int t = 0;
    while (n--) {
        int l; cin >> l;
        if (t == 0) {
            t = l;
        } else {
            t += l - 1;
        }
    }
    cout << t << endl;
}
