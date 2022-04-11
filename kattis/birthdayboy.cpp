#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int dateToDay(int m, int d) {
    tm bd = {};
    bd.tm_mon = m - 1;
    bd.tm_mday = d;
    mktime( &bd );
    return bd.tm_yday;
}

tm dayToDate(int day) {
    tm bd = {};
    if (day == 0) {
        bd.tm_mon = 11;
        bd.tm_mday = 31;
        return bd;
    }

    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++) {
        if (day < months[i]) {
            bd.tm_mon = i;
            bd.tm_mday = day + 1;
            break;
        }
        day -= months[i];
    }
    return bd;
}

int main() {

    int n; cin >> n;

    vector<pair<string, int>> birthdays;

    while (n--) {
        string name, b;
        cin >> name >> b;

        int m = atoi(b.substr(0, b.find('-')).c_str());
        int d = atoi(b.substr(b.find('-') + 1, b.size()).c_str());
        int day = dateToDay(m, d);
        
        day = day <= 300 ? day + 365 : day;

        birthdays.push_back(make_pair(name, day));
    }

    sort(birthdays.begin(), birthdays.end(), compare);

    int maxdiff = 0;
    int day = 0;

    for (int i = 0; i < birthdays.size(); i++) {
        int a = birthdays[(i + birthdays.size() - 1) % birthdays.size()].second;
        int b = birthdays[i].second;

        if ((i + birthdays.size() - 1) % birthdays.size() == birthdays.size() - 1) a -= 365;
        int diff = b - a;

        if (diff > maxdiff) {
            maxdiff = diff;
            day = b - 1;
        }
    }

    if (day >= 365) day -= 365;

    tm date = dayToDate(day);

    printf("%02d-%02d\n", date.tm_mon + 1, date.tm_mday);
}
