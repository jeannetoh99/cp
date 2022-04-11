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

struct vertex {
  int num = 0; // num of words that starts with this prefix
  int ans = 0; // ans if the query is this word
  char alphabet;
  bool exist;
  vector<vertex*> child;
  vertex(char a): alphabet(a), exist(false) { child.assign(26, NULL); }
};

class Trie {                                     // this is TRIE
private:                                         // NOT Suffix Trie
  vertex* root;
public:
  Trie() { root = new vertex('!'); }

  void insert(string word) {                     // insert a word into trie
    vertex* cur = root;
    int ans = 0;
    for (int i = 0; i < (int)word.size(); ++i) { // O(n)
      int alphaNum = word[i]-'a';
      cur->num++;
      ans += cur->num;
      if (cur->child[alphaNum] == NULL)          // add new branch if NULL
        cur->child[alphaNum] = new vertex(word[i]);
      cur = cur->child[alphaNum];
    }
    cur->num++; 
    ans += cur->num;
    cur->exist = true;
    cur->ans = ans;
  }

  int search(string word) {                     // true if word in trie
    vertex* cur = root;
    int ans = 0;
    for (int i = 0; i < (int)word.size(); ++i) { // O(m)
      int alphaNum = word[i]-'a';
      ans += cur->num;
      if (cur->child[alphaNum] == NULL)          // not found
        return ans;
      cur = cur->child[alphaNum];
    }
    return cur->exist ? cur->ans : ans + cur->num;
  }
};

///////////////////////////////// MAIN /////////////////////////////////

int solve(Trie &T, string query) {
    return T.search(query);
}

Trie buildTrie(vector<string> &words) {
    Trie T; 
    for (auto &str : words) {
        T.insert(str);
    }
    return T;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<string> words(n);
    FOR(i, 0, n) cin >> words[i];

    int q; cin >> q;
    vector<string> queries(q);
    FOR(i, 0, q) cin >> queries[i];


    Trie T = buildTrie(words);

    FOR(i, 0, q) {
        cout << solve(T, queries[i]) << "\n";
    }

}
