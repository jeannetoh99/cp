#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>

#define ll long long

using namespace std;

int main() {
   
    ll W; int N;
    int t = 1;
    while (true) {
        cin >> W >> N;
        if (!W && !N) break;
        
        vector <pair<string, ll> > words;
        ll cmax = 0;

        for (int i = 0; i < N; i++) {
            string S;
            ll C;
            cin >> S >> C;
            if (C < 5) continue;
            if (cmax < C) cmax = C;
            words.push_back(make_pair(S, C));
        }

        sort(words.begin(), words.end());

        ll totalHeight = 0;
        ll rowHeight = 0;
        ll rowWidth = 0;

        for (int i = 0; i < words.size(); i++) {
            string sw = words[i].first;
            ll cw = words[i].second;

            ll P = 8 + ceil((40.0 * (cw - 4.0)) / (cmax - 4.0));
            ll w = ceil(9.0 * sw.length() * P / 16.0);

            if (rowWidth != 0) w += 10;
            if (rowWidth + w > W) {
                totalHeight += rowHeight;
                rowHeight = 0;
                rowWidth = 0;
                w -= 10;
            }
            
            rowWidth += w;
            if (rowHeight < P) rowHeight = P;
        }

        if (rowHeight > 0) totalHeight += rowHeight;

        printf("CLOUD %d: %lld\n", t, totalHeight);
        t++;
    }

}

