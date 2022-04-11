#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t;
    double n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        cout << (int) (floor(n/3) * floor(m/3)) << '\n';
    }
    
    return 0;
}