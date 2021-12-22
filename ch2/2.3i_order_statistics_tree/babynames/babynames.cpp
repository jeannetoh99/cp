#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<string, null_type, less<string>, rb_tree_tag,
            tree_order_statistics_node_update> ost;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int command;

    ost female, male;
    string bn,s,e; int g, res;

    while (cin >> command && command) {
        switch (command) {
            case 1:
                cin>>bn>>g;
                if (g == 1) male.insert(bn);
                else female.insert(bn);
                break;
            case 2:
                cin>>bn;
                if (male.find(bn) != male.end()) male.erase(male.find(bn));
                else female.erase(female.find(bn));
                break;
            case 3:
                cin>>s>>e>>g;
                if (g == 0) {
                    res = male.order_of_key(e) - male.order_of_key(s) 
                        + female.order_of_key(e) - female.order_of_key(s);
                } else if (g == 1) {
                    res = male.order_of_key(e) - male.order_of_key(s);
                } else {
                    res = female.order_of_key(e) - female.order_of_key(s);
                }
                cout << res << "\n";
                break;
        }
    }

    return 0;

}
