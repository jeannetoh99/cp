#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n,m; 

    while (cin>>n>>m && (n||m)) {
        unordered_set<int> jack;
        int res=0;
        while(n--) {
            int x; cin>>x;
            jack.insert(x);
        }
        while(m--) {
            int x; cin>>x;
            if (jack.find(x) != jack.end()) res++;
        }
        cout << res << endl;
    }

}
