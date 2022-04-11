#include <iostream>

using namespace std;

int main() {

    string month;
    int day;

    cin >> month >> day;

    if ((month == "OCT" && day == 31) || (month == "DEC" && day == 25)) {
        cout << "yup\n";
    } else {
        cout << "nope\n";
    }

    return 0;
}