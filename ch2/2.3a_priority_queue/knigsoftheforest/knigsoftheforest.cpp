#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int k, n; cin >> k >> n;
    int y, p; cin >> y >> p;
    ii karlByYear = {y, p}; // year of entry, strength
    ii karlByStrength = {p, y};
    int r = n + k - 2;

    vector<ii> mooseByYear; mooseByYear.push_back(karlByYear);
    while (r--) {
        cin >> y >> p;
        mooseByYear.emplace_back(y, p);
    }
    sort(mooseByYear.begin(), mooseByYear.end());

    priority_queue<ii> mooseByStrength; int year = 2011;
    for (ii moose : mooseByYear) {
        mooseByStrength.emplace(moose.second, moose.first);
        if (mooseByStrength.size() == k) {
            if (mooseByStrength.top() == karlByStrength) {
                cout << year << endl;
                return 0;
            } else {
                mooseByStrength.pop(); year++;
            }
        }
    }
    

    cout << "unknown\n";
}
