#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    char prev = '0';

    while (true) {
        char curr; scanf("%c", &curr);
        if (curr == '\n') break;
        if (prev == '0') {
            prev = curr; 
            continue;
        } else {
            if (prev == 's' && curr == 's') {
                cout << "hiss" << endl;
                return 0;
            } else {
                prev = curr;
            }
        }
    }
    cout << "no hiss" << endl; 
    return 0;
}
