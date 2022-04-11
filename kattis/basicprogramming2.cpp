#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void twoSums(int A[], int n) {
    int i = 0;
    int j = n-1;
    while (i < j) {
        if (A[i] + A[j] == 7777) {
            printf("Yes\n");
            return;
        } else if (A[i] + A[j] > 7777) {
            j--;
        } else {
            i++;
        }
    }
    printf("No\n");
}

void checkUnique(int A[], int n) {
    for (int i=1; i<n; i++) {
        if (A[i] == A[i-1]) {
            printf("Contains duplicate\n");
            return;
        }
    }
    printf("Unique\n");
}

void action3(int A[], int n) {
    int maxF = 0;
    int max = -1;
    int f = 1;
    for (int i=1; i<n; i++) {
        if (A[i] == A[i-1]) {
            f++;
            if (f > n/2) {
                cout << A[i] << endl;
                return;
            }
        } else {
            f = 1;
        }
    }
    cout << -1 << endl;
    return;
}

void printMedian(int A[], int n) {
    if (n % 2 == 0) {
        cout << A[n/2-1] << " " << A[n/2] << endl;
    } else {
        cout << A[n/2] << endl;
    }
}

void printRange(int A[], int n) {
    bool first = true;
    for (int i=0; i<n; i++) {
        if (A[i] >= 100 && A[i] <= 999) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << A[i];
        }
    }
    cout << endl;
}

int main() {

    int n, t;  cin >> n >> t;
    int A[n];

    for (int i=0; i<n; i++) {
        cin >> A[i];
    }

    sort(A, A + n);

    if (t == 1) {
        twoSums(A, n);
    } else if (t == 2) {
        checkUnique(A, n);
    } else if (t == 3) {
        action3(A, n);
    } else if (t == 4) {
        printMedian(A, n);
    } else {
        printRange(A, n);
    }
}
