#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        double n;
        cin >> n;
        cout << ((int) abs(((n*567/9)+7492)*235/47-498) % 100 / 10) << '\n';
    }

    return 0;
}