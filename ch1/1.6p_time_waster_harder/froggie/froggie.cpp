#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

int main() {

    int l, w; cin >> l >> w;
    vector<iii> lanes;

    for (int j = 0; j < l; j++) {
        int o; // the starting offset of the first car
        int i; // the interval between cars
        int s; // the speed of the cars
        cin>>o>>i>>s;
        lanes.push_back(make_tuple(o,i,s));
    }

    int py = 0;
    int px; cin >> px;
    string moves; cin >> moves;

    unordered_map<char, ii> deltas = {
        {'U', make_pair(0, 1)},
        {'D', make_pair(0, -1)},
        {'L', make_pair(-1, 0)},
        {'R', make_pair(1, 0)}
    };

    bool hit = false;
    int t = 0;
    while (++t) {

        // if time exceeds number of moves, froggie will never reach top lane
        if (t > moves.size()) {
            hit = true;
            break;
        }

        char move = moves.at(t-1);
        // cout << t-1 << "->" << t << ": " << move << endl;
        
        // position before move
        int pyb = py;
        int pxb = py % 2 == l % 2 ? px : w - px - 1;

        // move
        px += deltas[move].first;
        py += deltas[move].second;

        // if reached top lane safe
        if (py > l) break;
        // if at bottom (no car) lane, definitely safe
        if (py == 0) continue;

        // get origin, interval and speed of cars in the lane 
        // (l-py) since lane numbers are reversed
        int o,i,s;
        tie(o, i, s) = lanes[l-py];

        // x position of froggie relative to direction of cars.
        int pxd = py % 2 == l % 2 ? px : w - px - 1;

        // get position of first car
        int first_car_pos = o + s * (t-1);

        // get position of last car that could possibly enter frame
        int last_car_pos = first_car_pos % i - i;

        // pointer to car
        int c = last_car_pos;
        
        // check if each car starting behind/at position of froggie will hit it
        while (c <= pxd) {
            // cout << c << "->" << c+s << endl;
            if ((c < pxd && pxd <= c+s) || (py == pyb && pxd == c && pxb == c + 1) || (s == 0 && pxd == c)) {
                hit = true;
                break;
            }
            c += i;
        }

        if (hit) break;
    }

    if (hit) {
        printf("squish\n");
    } else {
        printf("safe\n");
    }

}
