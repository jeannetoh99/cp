#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> ruler;
        int x; while (ss >> x) ruler.push_back(x);
        sort(ruler.begin(), ruler.end());
        int largestDistance = *(ruler.end()-1);
        int distances[largestDistance];
        memset(distances, 0, sizeof(int)*largestDistance);

        for (int i=0; i<ruler.size(); i++) {
            for (int j=i+1; j<ruler.size(); j++) {
                int diff = ruler[j] - ruler[i];
                distances[diff-1]++;
            }
        }
        vector<int> missing;
        bool isRuler = true;
        for (int i=0; i<largestDistance; i++) {
            if (distances[i] == 0) missing.push_back(i+1);
            if (distances[i] > 1) { isRuler = false; break; }
        }
        if (!isRuler) {
            cout << "not a ruler\n";
        } else if (missing.empty()) {
            cout << "perfect\n";
        } else {
            cout << "missing";
            for (int x : missing) cout << " " << x;
            cout << "\n";
        }
    }

}
