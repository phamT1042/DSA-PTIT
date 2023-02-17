#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long result (long long n, long long k) {
    if (k == 0) return 1;
    long long tmp = result(n, k / 2) % MOD;
    if (k % 2 == 1) return ((tmp * tmp) % MOD * n) % MOD;
    else return (tmp * tmp) % MOD;
}
int main() {
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        cout << result(n, k) << endl;
    }
}