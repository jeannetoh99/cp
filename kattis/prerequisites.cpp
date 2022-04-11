#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int k, m;

    while (true) {
        cin >> k;
        if (k == 0) break;
        cin >> m;
        unordered_set<string> courses;

        for (int i=0; i<k; i++) {
            string c; cin >> c;
            courses.insert(c);
        }

        bool meets = true;
        for (int i=0; i<m; i++) {
            int c; cin >> c;
            int r; cin >> r;

            while (c--) {
                string x; cin >> x;
                if (courses.find(x) != courses.end()) r--;
            }

            if (r > 0) meets = false;
        }

        if (meets) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

}
