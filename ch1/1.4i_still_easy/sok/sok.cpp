#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    double a,b,c; cin>>a>>b>>c;
    double i,j,k; cin>>i>>j>>k;

    double amt = min(a/i, min(b/j, c/k));

    printf("%f %f %f\n", a-i*amt, b-j*amt, c-k*amt);

}
