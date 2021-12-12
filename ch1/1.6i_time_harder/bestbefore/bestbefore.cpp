#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Date {
    int y;
    int m;
    int d;
};

void format(Date &d) {
    if (d.y < 2000) d.y = 2000 + d.y;
}

bool compare(Date a, Date b) {
    return a.y < b.y || (a.y == b.y && a.m < b.m) || (a.y == b.y && a.m == b.m && a.d < b.d);
}

bool isLeapYear(int y) {
    return y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0);
}

bool isValid(Date date) {
    unordered_set<int> longMonth = {1,3,5,7,8,10,12};

    if (date.m <= 0 || date.m > 12) return false;
    if (date.d <= 0) return false;
    if (isLeapYear(date.y) && date.m == 2 && date.d > 29) return false;
    if (!isLeapYear(date.y) && date.m == 2 && date.d > 28) return false;
    if (longMonth.find(date.m) != longMonth.end() && date.d > 31) return false;
    if (longMonth.find(date.m) == longMonth.end() && date.d > 30) return false;

    return true;
}

vector<int> stoi (vector<string> ss) {
    vector<int> result;

    for (string s : ss) {
        result.push_back(atoi(s.c_str()));
    }

    return result;
}

vector<string> split (string s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

int main() {

    string date; cin >> date;
    vector<string> s = split(date, '/');
    vector<int> nums = stoi(s);

    vector<Date> pos;

    pos.push_back((Date) {nums[0], nums[1], nums[2]});
    pos.push_back((Date) {nums[0], nums[2], nums[1]});
    pos.push_back((Date) {nums[1], nums[0], nums[2]});
    pos.push_back((Date) {nums[1], nums[2], nums[0]});
    pos.push_back((Date) {nums[2], nums[0], nums[1]});
    pos.push_back((Date) {nums[2], nums[1], nums[0]});

    vector<Date> valid;

    for (Date d : pos) {
        format(d);
        if (isValid(d)) valid.push_back(d);
    }

    if (valid.size() == 0) {
        printf("%s is illegal\n", date.c_str());
    } else {
        sort(valid.begin(), valid.end(), compare);
        Date d = valid[0];
        printf("%d-%02d-%02d\n", d.y, d.m, d.d);
    }
}
