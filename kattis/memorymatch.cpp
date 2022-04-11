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

void addCard(int c, string p, unordered_map<string, unordered_set<int>> &cards) {
    if (cards.find(p) == cards.end()) {
        cards[p] = unordered_set<int>();
    }
    cards[p].insert(c);
}

int main() {

    int N, K; cin >> N >> K;

    unordered_map<string, unordered_set<int>> cards;

    int matched = 0;

    while (K--) {
        int c1, c2;
        string p1, p2;
        cin >> c1 >> c2 >> p1 >> p2;
        addCard(c1, p1, cards);
        addCard(c2, p2, cards);
        if (p1 == p2) matched++;
    }

    int pairs = 0;
    int singles = 0;
    int opened = 0;

    for (auto card : cards) {
        if (card.second.size() == 2) pairs++;
        if (card.second.size() == 1) singles++;
        opened += card.second.size();
    }

    if (N - opened == singles) {
        cout << pairs - matched + singles << endl;
    } else if (singles == 0 && N - opened == 2) {
        cout << pairs - matched + 1 << endl;
    } else {
        cout << pairs - matched << endl;
    }

    return 0;
}
