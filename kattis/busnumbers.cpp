#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void printBuses(int start, int end) {
    if (start == end) {
        printf("%d", start);
    } else if (start == end -1) {
        printf("%d %d", start, end);
    } else {
        printf("%d-%d", start, end);
    }
}

int main() {

    bool buses[1002] = {0};
    int n; cin >> n;
    while (n--) {
        int b; cin >> b;
        buses[b] = 1;
    }

    int start=0;
    bool first = true;
    for (int i=1; i<=1001; i++) {
        if (buses[i] && start == 0) {
            start = i;
        } else if (!buses[i] && start != 0) {
            if (first) first = false; else cout << " ";
            printBuses(start, i-1);
            start = 0;
        }
    }
    cout << endl;
}
