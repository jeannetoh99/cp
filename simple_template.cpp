#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

///////////////////////// PAIR HASH /////////////////////////
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

//////////////////////////// DEBUGGING CODE ////////////////////////////
template<typename T> 
void print(T &x) { cout << x; }

template<typename T1, typename T2>
void print(pair<T1,T2> &p) { cout << "(" << p.first << "," << p.second << ")"; }

template<typename T>
void print(vector<T> &v) {
    cout << "[";
    for (int i=0; i<v.size(); i++) { if (i>0) cout << ", "; print(v[i]); }
    cout << "]" <<  endl;
}

template<typename T>
void print(vector<vector<T>> &v) {
    if (v.empty()) { cout << "empty 2d vector\n"; return; }
    for (int i=0; i<v.size(); i++) {
        cout << i << ": ";
        for (int j=0; j<v[i].size(); j++) {
            if (j>0) cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }
}

///////////////////////////////// MAIN /////////////////////////////////

int solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << solve() << endl;
}
