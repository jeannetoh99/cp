#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void shuffle(int shuffled[], string type, int n) {

    int deck[n];
    copy(shuffled, shuffled + n, deck);

    int i = 0;
    int j = n / 2;

    if (n % 2 == 1 && type == "out") j++;

    for (int k = 0; k < n; k++) {
        if (type == "out" && k % 2 == 0) {
            shuffled[k] = deck[i++];
        } else if (type == "out" && k % 2 == 1) {
            shuffled[k] = deck[j++];
        } else if (type == "in" && k % 2 == 0) {
            shuffled[k] = deck[j++];
        } else {
            shuffled[k] = deck[i++];
        }
    }
}

int main() {

    int n; cin >> n;
    string type; cin >> type;
    int deck[n];
    for (int i = 0; i < n; i++) {
        deck[i] = i;
    }

    int shuffled[n];
    copy(deck, deck + n, shuffled);

    int ans = 0;
    
    while (ans == 0 || !equal(deck, deck + n, shuffled)) {
        shuffle(shuffled, type, n);
        ans++;
    }

    cout << ans << endl;
}
