#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int N; cin >> N;
    int tea[N];

    for (int i = 0; i < N; i++) {
        cin >> tea[i];
    }

    int M; cin >> M;
    int toppings[M];

    for (int i = 0; i < M; i++) {
        cin >> toppings[i];
    }

    int minPrice = 1e9;

    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        while (K--) {
            int t; cin >> t;
            if (minPrice > tea[i] + toppings[t-1]) minPrice = tea[i] + toppings[t-1];
        }
    }

    int X; cin >> X;

    if (X < minPrice) {
        cout << 0 << endl;
    } else {
        cout << X / minPrice - 1 << endl;
    }
}
