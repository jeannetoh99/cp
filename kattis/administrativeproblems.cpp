#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

// TODO: this solution is not fully correct yet.
struct car {
    int price;
    int pickupcost;
    int costperkm;
};
struct event {
    char type; // type of event
    string c; // name of type of car
};

int main() {
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        unordered_map<string, car> cars;
        for (int i=0;i<n;i++) {
            string N; cin>>N;
            int p,q,k; cin>>p>>q>>k;
            cars[N] = {p,q,k};
        }
        map<string, int> costs;
        unordered_map<string, event> events;
        unordered_set<string> inconsistent;
        for (int i=0;i<m;i++) {
            int t; string S; char e; cin>>t>>S>>e;
            if (costs.find(S) == costs.end()) costs[S] = 0;
            if (e == 'p') {
                string C; cin >> C;
                if (events.find(S) != events.end() && events[S].type != 'r') {
                    inconsistent.insert(S); continue;
                }
                events[S] = {e, C};
                // cout << events[S].type << " " << events[S].c << endl;
                costs[S] += cars[C].pickupcost;
            } else if (e == 'r') {
                int d; cin >> d;
                // if car was never picked up / just returned, inconsistent
                if (events.find(S) == events.end() || events[S].type == 'r') {
                    inconsistent.insert(S); continue;
                }
                event p = events[S];
                events[S] = {e, p.c};
                costs[S] += cars[p.c].costperkm * d;
            } else if (e == 'a') {
                double s; cin >> s;
                // if car was never picked up / just returned, inconsistent
                if (events.find(S) == events.end() || events[S].type == 'r') {
                    inconsistent.insert(S); continue;
                }
                event p = events[S];
                events[S] = {e, p.c};
                costs[S] += ceil((double) cars[p.c].price * (s/100));
            }
        }
        for (auto it=costs.begin(); it!=costs.end(); it++) {
            string spy = (*it).first;
            int cost = (*it).second;
            if (inconsistent.find(spy) == inconsistent.end() && events[spy].type == 'r') {
                printf("%s %d\n", spy.c_str(), cost);
            } else {
                printf("%s INCONSISTENT\n", spy.c_str());
            }
        }
    }
}
