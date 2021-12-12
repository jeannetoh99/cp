#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main() {

    int X, Y, N;
    cin >> X >> Y >> N;

    for (int i=1; i<=N; i++) {
        if (i % X == 0 && i % Y == 0) {
            printf("FizzBuzz\n");
        } else if (i % X == 0) {
            printf("Fizz\n");
        } else if (i % Y == 0) {
            printf("Buzz\n");
        } else {
            cout << i << endl;
        }
    }

    return 0;
}
