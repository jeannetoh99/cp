#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;

    unordered_map<string, ii> cats; // name, severity, time of arrival
    map<ii, string> infections; // severity, time of arrival, name
    
    for (int t=0; t<n; t++) {
        int cmd; cin >> cmd;
        if (cmd == 0) {
            string name; int infectionLevel;
            cin >> name >> infectionLevel;
            cats.insert({name, {-infectionLevel, t}});
            infections.insert({{-infectionLevel, t}, name});
        } else if (cmd == 1) {
            string name; int increaseInfection;
            cin >> name >> increaseInfection;
            infections.erase(infections.find(cats[name]));
            cats[name] = {cats[name].first - increaseInfection, cats[name].second};
            infections.insert({cats[name], name});
        } else if (cmd == 2) {
            string name; cin >> name;
            infections.erase(infections.find(cats[name]));
            cats.erase(cats.find(name));
        } else {
            if (infections.empty()) {
                printf("The clinic is empty\n");
            } else {
                cout << (*infections.begin()).second << endl;
            }
        }
    }

}
