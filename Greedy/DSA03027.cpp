#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    long long a[n], res = 0;
    for (long long &x : a) {
        cin >> x;
        res += x + abs(x);
    }
    cout << res;
}