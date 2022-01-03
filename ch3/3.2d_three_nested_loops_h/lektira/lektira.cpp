#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string s; cin >> s;
    string best = s;

    for (int i=0; i<s.size()-2; i++) {
        for (int j=i+1; j<s.size()-1; j++) {
            string t = s;
            reverse(t.begin(), t.begin()+i+1);
            reverse(t.begin()+i+1, t.begin()+j+1);
            reverse(t.begin()+j+1, t.end());
            if (t < best) best = t;
        }
    }

    cout << best << endl;
}
