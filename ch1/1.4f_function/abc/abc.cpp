#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int abc[3];
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc, abc + 3);
    
    for (int i = 0; i < 3; i++) {
        char x; cin >> x;
        if (i != 0) cout << " ";
        cout << abc[x - 'A'];
    }
    cout << endl;
}
