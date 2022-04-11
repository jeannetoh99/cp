#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int d; string m;
        cin >> d >> m;

        if ((m == "Mar" && d >= 21) || (m == "Apr" && d <= 20)) {
            cout << "Aries" << endl;
        } else if ((m == "Apr" && d >= 21) || (m == "May" && d <= 20)) {
            cout << "Taurus" << endl;
        } else if ((m == "May" && d >= 21) || (m == "Jun" && d <= 21)) {
            cout << "Gemini" << endl;
        } else if ((m == "Jun" && d >= 22) || (m == "Jul" && d <= 22)) {
            cout << "Cancer" << endl;
        }  else if ((m == "Jul" && d >= 23) || (m == "Aug" && d <= 22)) {
            cout << "Leo" << endl;
        }  else if ((m == "Aug" && d >= 23) || (m == "Sep" && d <= 21)) {
            cout << "Virgo" << endl;
        }  else if ((m == "Sep" && d >= 22) || (m == "Oct" && d <= 22)) {
            cout << "Libra" << endl;
        }  else if ((m == "Oct" && d >= 23) || (m == "Nov" && d <= 22)) {
            cout << "Scorpio" << endl;
        }  else if ((m == "Nov" && d >= 23) || (m == "Dec" && d <= 21)) {
            cout << "Sagittarius" << endl;
        }  else if ((m == "Dec" && d >= 22) || (m == "Jan" && d <= 20)) {
            cout << "Capricorn" << endl;
        }  else if ((m == "Jan" && d >= 21) || (m == "Feb" && d <= 19)) {
            cout << "Aquarius" << endl;
        }  else if ((m == "Feb" && d >= 20) || (m == "Mar" && d <= 20)) {
            cout << "Pisces" << endl;
        }

    }
}
