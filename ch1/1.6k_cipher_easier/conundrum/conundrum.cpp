#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    string line; cin >> line;
    char per[3] = {'P', 'E', 'R'};

    int days = 0;
    for (int i = 0; i < line.size(); i++) {
        char ch = line.at(i);
        if (ch != per[i%3]) days++;
    }

    cout << days << endl;

}
