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

vector<pair<char, string>> pp = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."}, 
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'_', "..--"},
    {'.', "---."},
    {',', ".-.-"},
    {'?', "----"},
};

unordered_map<char, string> m;
unordered_map<string, char> mb;

void solve(string s) {
    vector<int> nums;
    string text;

    for (char c : s) {
        text += m[c];
        nums.push_back(m[c].size());
    }

    reverse(nums.begin(), nums.end());

    string res; int idx = 0;
    for (int i : nums) {
        res += mb[text.substr(idx, i)];
        idx += i;
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (auto p : pp) {
        m.emplace(p.first, p.second);
        mb.emplace(p.second, p.first);
    }

    string s;
    while (cin >> s) solve(s);
}
