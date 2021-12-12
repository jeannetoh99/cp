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
    int a,b;
    cin >> a >> b;

    int cw = ((360 - a) + b) % 360;
    int acw = (a + (360 - b)) % 360;

    if (cw > acw) {
        cout << -acw << endl;
    } else {
        cout << cw << endl;
    }
}