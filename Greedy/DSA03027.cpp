#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    long long a[n], res = 0;
    for (long long &x : a) {
        cin >> x;
        if (x > 0) res += 2 * x;
    }
    cout << res;
}