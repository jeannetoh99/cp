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

string opposite(string d) {
    if (d == "North") {
        return "South";
    } else if (d == "West") {
        return "East";
    } else if (d == "South") {
        return "North";
    } else {
        return "West";
    }
}

string right(string d) {
    if (d == "North") {
        return "West";
    } else if (d == "West") {
        return "South";
    } else if (d == "South") {
        return "East";
    } else {
        return "North";
    }
}

int main() {
    string a, b, c; cin >> a >> b >> c;

    bool row = (opposite(a) == b && right(a) == c) 
        || (right(b) == a && (opposite(a) == c || right(a) == c) );

    cout << (row ? "Yes" : "No") << endl;

}