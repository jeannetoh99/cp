#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    int p[3] = {0};
    string names[3] = {"Adrian", "Bruno", "Goran"};

    char a[12] = {'A','B','C','A','B','C','A','B','C','A','B','C'};
    char b[12] = {'B','A','B','C','B','A','B','C','B','A','B','C'};
    char g[12] = {'C','C','A','A','B','B','C','C','A','A','B','B'};

    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        if (x == a[i % 12]) p[0]++;
        if (x == b[i % 12]) p[1]++;
        if (x == g[i % 12]) p[2]++;
    }

    int l = 0;
    vector<string> winners;

    for (int i = 0; i < 3; i++) {
        if (p[i] > l) {
            l = p[i];
            winners.clear();
            winners.push_back(names[i]);
        } else if (p[i] == l) {
            winners.push_back(names[i]);
        }
    }

    printf("%d\n", l);
    
    for (string winner : winners) {
        printf("%s\n", winner.c_str());
    }
}
