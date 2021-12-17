#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {
    
    int t; cin >> t;

    while (t--) {
        string prog; cin >> prog;
        int n; cin >> n;
        cin.ignore();
        deque<int> l;
        if (n == 0) cin.ignore();
        while (n--) {
            cin.ignore(); 
            int x; 
            cin >> x;
            l.push_back(x);
        }
        cin.ignore();
        bool front = true;
        bool error = false;
        for (char c : prog) {
            if (c == 'R') {
                front = !front;
            } else {
                if (l.empty()) {
                    error = true;
                    break;
                }
                if (front) {
                    l.pop_front();
                } else {
                    l.pop_back();
                }
            }
        }
        if (error) {
            cout << "error\n";
            continue;
        }
        
        cout << "[";
        bool first = true;
        if (front) {
            for (auto it=l.cbegin(); it!=l.cend(); ++it) {
                if (first) {
                    first = false;
                } else {
                    cout << ",";
                }
                cout << *it;
            }
        } else {
            for (auto it=l.crbegin(); it!=l.crend(); ++it) {
                if (first) {
                    first = false;
                } else {
                    cout << ",";
                }
                cout << *it;
            }
        }
        cout << "]" << endl;
    }

}
