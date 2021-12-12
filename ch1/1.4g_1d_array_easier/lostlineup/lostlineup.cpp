#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int n; cin >> n;
    int l[n-1];

    for (int i=0; i<n-1; i++) {
        int p; cin >> p;
        l[p] = i+2; 
    }

    cout << 1;

    for (int i = 0; i < n-1; i++) {
        cout << " " << l[i];
    } 
    cout << endl;
}