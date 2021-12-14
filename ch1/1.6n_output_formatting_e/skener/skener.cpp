#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int r, c, zr, zc; cin>>r>>c>>zr>>zc;

    for (int i = 0; i < r; i++) {
        string line; cin >> line;
        char newline[line.size()*zc + 1];
        for (int j = 0; j < line.size(); j++) {
            for (int z = 0; z < zc; z++) {
                newline[j*zc+z] = line.at(j);
            }
        }
        newline[line.size()*zc] = '\0';
        for (int j = 0; j < zr; j++) {
            cout << newline << endl;
        }
    }
}
