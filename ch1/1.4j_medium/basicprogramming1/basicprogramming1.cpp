#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {

    int N, t; cin >> N >> t;
    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    switch (t) {
        case 1: {
            printf("7\n");
            break;
        }
        case 2: {
            if (A[0] > A[1]) {
                printf("Bigger\n");
            } else if (A[0] == A[1]) {
                printf("Equal\n");
            } else {
                printf("Smaller\n");
            }
            break;
        }
        case 3: {
            sort(&A[0], &A[3]);
            printf("%d\n", A[1]);
            break;
        }
        case 4: {
            long s = 0;
            for (int a : A) {
                s += (long) a;
            }
            printf("%ld\n", s);
            break;
        }
        case 5: {
            long s = 0;
            for (int a : A) {
                if (a%2==0) s += (long) a;
            }
            printf("%ld\n", s);
            break;
        }
        case 6: {
            for (int i = 0; i < N; i++) {
                cout << (char) ('a' + (A[i] % 26));
            }
            cout << endl;
            break;
        }
        case 7: {
            int i = 0;
            bool v[N]; memset(v, false, N);

            while (true) {
                if (v[i]) {
                    printf("Cyclic\n");
                    break;
                }
                v[i] = true;
                i = A[i];
                if (i >= N) {
                    printf("Out\n");
                    break;
                }
                if (i == N - 1) {
                    printf("Done\n");
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
