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

int main() {

    unordered_map<char, pair<int, int>> scores;
    scores['A'] = make_pair(11, 11);
    scores['K'] = make_pair(4, 4);
    scores['Q'] = make_pair(3, 3);
    scores['J'] = make_pair(20, 2);
    scores['T'] = make_pair(10, 10);
    scores['9'] = make_pair(14, 0);
    scores['8'] = make_pair(0, 0);
    scores['7'] = make_pair(0, 0);

    int N; 
    char B; 
    cin >> N >> B;

    char v, s;
    N*=4;

    int total = 0;
    while (N--) {
        cin >> v >> s;
        if (s == B) {
            total += scores[v].first;
        } else {
            total += scores[v].second;
        }
    }

    cout << total << endl;

}
