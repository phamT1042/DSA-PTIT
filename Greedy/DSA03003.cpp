#include<bits/stdc++.h>
using namespace std;
int main() {
    int MOD = 1e9 + 7;
    int t; cin >> t;
    while (t--) {
        int n, res = 0; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            res += (a[i] % MOD * i % MOD) % MOD;
            res %= MOD;
        }
        cout << res << endl;
    }
    return 0;
}