#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

    int n; cin >> n;

    while (n--) {

        string name, s, b;
        int s_y, s_m, s_d, b_y, b_m, b_d, c;

        cin >> name >> s >> b >> c;

        sscanf(s.c_str(), "%d/%d/%d", &s_y, &s_m, &s_d);
        sscanf(b.c_str(), "%d/%d/%d", &b_y, &b_m, &b_d);

        if (s_y >= 2010 || b_y >= 1991) {
            printf("%s eligible\n", name.c_str());
        } else if (c >= 41) {
            printf("%s ineligible\n", name.c_str());
        } else {
            printf("%s coach petitions\n", name.c_str());
        }

    }

    return 0;

}