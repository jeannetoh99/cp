#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string M, s, e; 
    int d, y;

    while (cin >> M >> d >> y >> s >> e) {
        int s_t = atoi(s.substr(0, s.find(':')).c_str()) * 60 + atoi(s.substr(s.find(':') + 1, s.size()).c_str());
        int e_t = atoi(e.substr(0, e.find(':')).c_str()) * 60 + atoi(e.substr(e.find(':') + 1, e.size()).c_str());

        int diff = e_t - s_t;
        int h = diff / 60;
        int m = diff % 60;
        printf("%s %d %d %d hours %d minutes\n", M.c_str(), d, y, h, m);
    }

}
