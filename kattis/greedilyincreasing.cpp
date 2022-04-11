#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    vector<int> gis;

    int p; cin >> p;
    gis.push_back(p);
    n--;
    
    while (n--) {
        int c; cin >> c;
        if (c > p) {
            p = c;
            gis.push_back(p);
        }
    }

    cout << gis.size() << endl;

    for (int i = 0; i < gis.size(); i++) {
        if (i != 0) cout << " ";
        cout << gis[i];
    }
    cout << endl;

}
