#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n; cin >> n;

    int score = 0;
    char prev; cin >> prev;
    n--;

    while (n--) {
        char curr; cin >> curr;
        if (curr == prev) score++;
        prev = curr;
    }

    cout << score << endl;
}
