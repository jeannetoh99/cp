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
    int n,k; cin >> n >> k;
    int d,s; cin >> d >> s;

    int td = n * d;
    int ks = k * s;
    int r = td - ks;

    double rd = (double) r / (double) (n-k);

    if (rd <= 0 || rd > 100) {
        cout << "impossible\n";
    } else {
        cout << fixed << setprecision(9) << rd << endl;
    }
}