#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
#define vll vector<ll>
#define FOR(i, j, k) for (int i=j ; i<k ; i++)
#define RFOR(i, j, k) for (int i=j ; i>=k ; i--)
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
#define INF (int)1e9
#define MOD 1000000007
#define fi first
#define se second
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////

vector<char> hard = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};
unordered_set<char> ishard(hard.begin(), hard.end());
vector<char> endings = {'a', 'o', 'u'};

char findNearest(vector<char> &list, char c) {
    auto it = lower_bound(list.begin(), list.end(), c);
    if (it == list.end()) return list[list.size()-1];
    if (it == list.begin()) return *list.begin();
    char h = (abs(*it-c) >= abs(*(it-1)-c) ? *(it-1) : *it);

    return h;
}

void solve() {
    string s; bool first = true;
    while (cin >> s) {
        if (!first) cout << " ";
        first = false; 

        string res;

        char h = findNearest(hard, tolower(s[0]));
        res += islower(s[0]) ? h : toupper(h);

        char lh = h;
        for (int i=1; i<s.size(); i++) {
            if (s[i] == '-') continue;
            if (ishard.count(s[i])) {
                if (i > s.find('-')) res += h;
                else res += s[i];
                lh = s[i]; 
            }
            else res += s[i];
        }
        
        if (ishard.count(tolower(res[res.size()-1]))) {
            res += findNearest(endings, lh);
            res += 'h';
        }
        cout << res;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
