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
    string hey; cin >> hey;
    int e = (hey.size() - 2) * 2;
    
    cout << 'h';
    while (e--) {
        cout << 'e';
    }
    cout << 'y' << endl;
}