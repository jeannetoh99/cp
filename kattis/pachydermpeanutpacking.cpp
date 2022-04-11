#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

struct Box {
    double x1, y1, x2, y2;
};

bool inBox(double x, double y, Box b) {
    // printf("%f %f, %f %f %f %f\n", x, y, b.x1, b.y1, b.x2, b.y2);
    return x >= b.x1 && x <= b.x2 && y >= b.y1 && y <= b.y2;
}

string findLocation(double x, double y, vector<pair<string, Box>> &boxes) {
    for (auto b : boxes) {
        if (inBox(x, y, b.second)) {
            return b.first;
        }
    }
    return "floor";
}

int main() {

    int n;

    bool first = true;

    while (cin >> n && n) {
        if (first) {
            first = false;
        } else {
            printf("\n");
        }
        vector<pair<string, Box>> boxes;
        while (n--) {
            Box b; 
            cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
            string size; cin >> size;
            boxes.push_back(make_pair(size, b));
        }
        int m; cin >> m;
        while (m--) {
            double x, y; cin >> x >> y;
            string size; cin >> size;
            string location = findLocation(x, y, boxes);
            if (size == location) {
                printf("%s correct\n", size.c_str());
            } else {
                printf("%s %s\n", size.c_str(), location.c_str());
            }
        }
    }
}
