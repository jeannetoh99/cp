#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int n; cin >> n;
    unordered_map<int, string> points;

    points.insert({0, ""});
    for (int i=1; i<=20; i++) {
        points.insert({i, "single " + to_string(i) + "\n"});
        points.insert({2*i, "double " + to_string(i) + "\n"});
        points.insert({3*i, "triple " + to_string(i) + "\n"});
    }

    for (pair<int, string> p1 : points) {
        for (pair<int, string> p2 : points) {
            for (pair<int, string> p3 : points) {
                if (p1.first + p2.first + p3.first == n) {
                    cout << p1.second << p2.second << p3.second;
                    return 0;
                }
            }
        }
    }
    cout << "impossible\n";
}
