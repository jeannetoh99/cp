#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int L, x;
    cin >> L >> x;

    int ans = 0;
    while (x--) {
        string m;
        int p; 
        cin >> m >> p;
        if (m == "leave") {
            L += p;
        } else if (p <= L) {
            L-=p;
        } else {
            ans++;
        }
    }

    cout << ans << endl;
}