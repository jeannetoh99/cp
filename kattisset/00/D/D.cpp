#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

bool isAllowed(char c) {
    return (c == '?' || c == '!' || c == ','
        || c == '.' || c == ' ' || isalnum(c));

}

void clearImage(vector<string> &page, int sx, int sy, int tx, vector<vector<bool>> &checked) {
    int y = sy;
    for (int x=sx; x<tx; x++) page[y][x] = ' '; y++;
    while (page[y][sx+1] != '+') {
        for (int x=sx; x<tx; x++) {
            page[y][x] = ' ';
            checked[y][x] = true;
        }
        y++;
    }
    for (int x=sx; x<tx; x++) {
        page[y][x] = ' ';
        checked[y][x] = true;
    }
}

void checkImage(vector<string> &page, int sx, int sy, vector<vector<bool>> &checked) {
    int pageWidth = page[0].size();
    int pageHeight = page.size();
    int tx = sx, y = sy;
    while (tx < page[0].size() && page[y][tx] == '+') tx++;  
    int imageWidth = tx - sx;
    for (int x=sx; x < tx; x++) checked[y][x] = true;
    y++;

    while (page[y][sx+1] != '+') {
        checked[y][sx] = true;
        for (int x=sx+1; x < tx - 1; x++) {
            if (checked[y][x]) continue;
            if (page[y][x] == '+') {
                checkImage(page, x, y, checked);
            } else if (!isAllowed(page[y][x])) {
                clearImage(page, sx, sy, tx, checked);
                return;
            }
            checked[y][x] = true;
        }
        checked[y][tx-1] = true;
        y++;
    }
    for (int x=sx; x < tx; x++) checked[y][x] = true;
}

int main() {
    int h,w; cin >> h >> w;
    cin.ignore();
    vector<string> page;
    for (int y=0; y<h; y++) {
        string x; getline(cin, x);
        page.push_back(x);
    }
    vector<vector<bool>> checked(h, vector<bool>(w, false));
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            if (checked[y][x]) continue;
            if (page[y][x] == '+') checkImage(page, x, y, checked);
            checked[y][x] = true;
        }
    }
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            cout << page[y][x];
        }
        cout << "\n";
    }
}
