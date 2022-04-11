#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>
using namespace std;

///////////////////////////////// MAIN /////////////////////////////////

int tortoise = 0;
int hare = 0;

void askTortoise() {
    cout << "ASK SPIKE" << endl;
}

bool returnTortoise() {
    tortoise = 0;
    cout << "RETURN SPIKE" << endl;
    int s, e; cin >> s >> e;
    return e;
}

bool nextTortoise() { // TORTOISE
    tortoise++;
    cout << "NEXT SPIKE" << endl;
    int s, e; cin >> s >> e;
    return e;
}

bool nextHare() { // HARE
    hare++;
    cout << "NEXT GABBY" << endl;
    int s, e; cin >> s >> e;
    return e;
}

int main() {
    int n; cin >> n;

    if (n < 30000) {
        while (n--) nextTortoise();
        askTortoise();
        return 0;
    }

    while (true) {
        nextTortoise(); 
        nextHare(); 
        if (nextHare()) break;
    }

    returnTortoise();
    while (!nextTortoise()) {}

    int cycleL = hare - tortoise;
    int end = (n - tortoise) % cycleL;
    while (end--) nextTortoise();
    askTortoise();
    return 0;

}