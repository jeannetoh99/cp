#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;

void printString(pair<string, vector<int>> arr[], int a) {
    cout << arr[a].first;
    for (int b : arr[a].second) {
        printString(arr, b);
    }
}

int main() {

    int n; cin >> n;
    pair<string, vector<int>> arr[n]; 

    for (int i=0; i<n; i++) {
        string x; cin>>x;
        arr[i] = make_pair(x, vector<int>());
    }

    int a, b;
    for (int i=1; i<n; i++) {
        cin>>a>>b;
        arr[a-1].second.push_back(b-1);
    }

    printString(arr, a-1);
    cout << endl;

}
