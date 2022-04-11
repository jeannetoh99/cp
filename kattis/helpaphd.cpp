#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {

    int N; cin >> N;

    string line; 
    getline(cin, line);

    while (N--) {
        
        getline(cin, line);

        if (line.find('+') != -1) {
            int a,b;
            sscanf(line.c_str(), "%d+%d", &a, &b);
            cout << a + b << endl;
        } else {
            cout << "skipped" << endl;
        }

    }

}