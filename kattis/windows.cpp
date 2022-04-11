#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

string DOES_NOT_FIT = "window does not fit";
string NO_WINDOW = "no window at given position";

struct Window {
    int x, y, w, h, c;
};

bool coordInWindow(int x, int y, Window w) {
    return x >= w.x && x <= w.x + w.w && y >= w.y && y <= w.y + w.h;
}

int windowsOverlap(Window w1, Window w2) {
    int x1 = w1.x, y1 = w1.y, x2 = w1.x + w1.w, y2 = w1.y + w1.h;
    int x3 = w2.x, y3 = w2.y, x4 = w2.x + w2.w, y4 = w2.y + w2.h;

    return coordInWindow(x1, y1, w2) 
                || coordInWindow(x2, y2, w2)
                || coordInWindow(x3, y3, w1)
                || coordInWindow(x4, y4, w1);
}

int findWindow(int x, int y, vector<Window> &windows) {
    for (int i = 0; i < windows.size(); i++) {
        if (coordInWindow(x, y, windows[i])) {
            return i;
        }
    }
    return -1;
}

bool handleOpen(Window w, vector<Window> &windows, int xmax, int ymax) {
    if (w.x < 0 || w.x + w.w > xmax || w.y < 0 || w.y > ymax) return false;

    for (Window ww : windows) {
        if (windowsOverlap(w, ww)) return false;
    }

    windows.push_back(w);
    return true;
}

int handleResize(Window w, vector<Window> &windows, int xmax, int ymax) {
    int index = -1;
    bool overlap = false;
    for (int i = 0; i < windows.size(); i++) {
        if (coordInWindow(w.x, w.y, windows[i])) {
            index = i;
        } else {
            if (windowsOverlap(w, windows[i])) overlap = true;
        }
    }

    if (index == -1) return 1;
    if (overlap) return 2;

    windows[index].w = w.w;
    windows[index].h = w.h;

    return 0;
}

bool handleClose(int x, int y, vector<Window> &windows) {
    for (int i = 0; i < windows.size(); i++) {
        if (coordInWindow(x, y, windows[i])) {
            windows.erase(windows.begin() + i);
            return true;
        }
    }
    return false;
}

bool compareByXPositions(Window a, Window b) {
    return a.x < b.x;
}

bool compareByYPositions(Window a, Window b) {
    return a.y < b.y;
}

bool overlap(int y1, int h1, int y2, int h2) {
    return (y1 + h1 < y2 || y2 + h2 < y1);
}

int handleMove(int x, int y, int dx, int dy, vector<Window> &windows, int xmax, int ymax) {
    if (dx != 0) {
        if (dx > 0) {
            sort(windows.begin(), windows.end(), compareByXPositions);
        } else {
            sort(windows.begin(), windows.end(), -compareByXPositions);
        }
        int wi = findWindow(x, y, windows);
        if (wi == -1) return 1;
        int left = dx;
        vector<int> diff;
        vector<Window> win;
        int i = wi;
        while (x < xmax && left > 0 && i < windows.length()) {
            int d;
            int j = i+1;
            while (j < windows.length() - 1 && !overlap(windows[i].y, windows[i].h, windows[j].y, windows[j].h)) j++;
            if (j == windows.length()) {
                d = xmax - (windows[i].x + windows[i].w);
            } else {
                d = windows[j].x - (windows[i].x + windows[i].w);
            }
            d = min(d, left);
            diff.push_back(d);
            win.push_back(windows[i]);
            left -= d;
            i = j;
        }

        int td = 0;
        for (int k = diff.length() - 1; k >= 0; k--) {
            td += diff[k];
            win[k].x += td;
        }
        return dx - left;
    } else {
        if (dy > 0) {
            sort(windows.begin(), windows.end(), compareByYPositions);
        } else {
            sort(windows.begin(), windows.end(), -compareByYPositions);
        }
        int wi = findWindow(x, y, windows);
        if (wi == -1) return 1;
        int left = dx;
        vector<int> diff;
        vector<Window> win;
        int i = wi;
        while (y < ymax && left > 0 && i < windows.length()) {
            int d;
            int j = i+1;
            while (j < windows.length() - 1 && !overlap(windows[i].x, windows[i].w, windows[j].x, windows[j].w)) j++;
            if (j == windows.length()) {
                d = ymax - (windows[i].y + windows[i].h);
            } else {
                d = windows[j].y - (windows[i].y + windows[i].h);
            }
            d = min(d, left);
            diff.push_back(d);
            win.push_back(windows[i]);
            left -= d;
            i = j;
        }

        int td = 0;
        for (int k = diff.length() - 1; k >= 0; k--) {
            td += diff[k];
            win[k].y += td;
        }
        return dx - left;
    }
}

int main() {

    int xmax, ymax; cin >> xmax >> ymax;

    string command;
    vector<Window> windows;

    int i = 1;
    while (cin >> command) {
        if (command == "OPEN") {
            Window w; cin >> w.x >> w.y >> w.w >> w.h;
            w.c = i;
            bool res = handleOpen(w, windows, xmax, ymax);
            if (!res) {
                printf("Command %d: OPEN - %s\n", i, DOES_NOT_FIT.c_str());
            }
        } else if (command == "RESIZE") {
            Window w; cin >> w.x >> w.y >> w.w >> w.h;
            int res = handleResize(w, windows, xmax, ymax);
            if (res == 1) printf("Command %d: RESIZE - %s\n", i, NO_WINDOW.c_str());
            if (res == 2) printf("Command %d: RESIZE - %s\n", i, DOES_NOT_FIT.c_str());
        } else if (command == "CLOSE") {
            int x, y; cin >> x >> y;
            bool res = handleClose(x, y, windows);
            if (!res) printf("Command %d: CLOSE - %s\n", i, NO_WINDOW.c_str());
        } else { // MOVE
            int x, y, dx, dy;
            int res = handleMove(x, y, dx, dy, windows, xmax, ymax);
        }

        i++;
    }

}
