#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    map<ll, ll> bst; // val, depth
    ll c=0;
    ll x; cin >> x; n--;
    bst.insert({x, 0});
    cout << c << endl;

    while (n--) {
        cin >> x;
        auto post = bst.upper_bound(x);
        auto pre = post; pre--;
        ll d;
        if (bst.size() == 1) {
            d = 0;
        } else if (post == bst.begin()) {
            d = (*post).second;
        } else if (post == bst.end()) {
            d = (*pre).second;
        } else {
            d = max((*post).second, (*pre).second);
        }
        bst.insert({x, d+1});
        c += (d+1);
        cout << c << endl;
    }

}

// struct Node {
//     int val;
//     Node* left;
//     Node* right;
// };

// Node* newNode(int val) {
//     Node* temp = (Node*) malloc(sizeof(Node));
//     temp->val = val;
//     temp->left = temp->right = NULL;
//     return temp;
// }

// int insertNode(Node &root, int val) {
//     if (val < root.val && root.left == NULL) {
//         root.left = newNode(val);
//         return 1;
//     }
//     if (val > root.val && root.right == NULL) {
//         root.right = newNode(val);
//         return 1;
//     }
//     if (val < root.val) {
//         return insertNode(*root.left, val) + 1;
//     } else {
//         return insertNode(*root.right, val) + 1;
//     }
// }

// int main() {

//     int n; cin >> n;
//     int x; cin >> x;
//     Node root = *newNode(x);
//     n--; 
//     int c=0;
//     cout << c << endl;

//     while (n--) {
//         cin >> x;
//         int d = insertNode(root, x);
//         c += d;
//         cout << c << endl;
//     }
// }
