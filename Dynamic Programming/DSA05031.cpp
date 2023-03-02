#include<bits/stdc++.h>
using namespace std;
long long dp[10001];
int main() {
    long long MOD = 1e9 + 7;
    for (int i = 1; i <= 100; i++) dp[i * i] = 1;
    for (int i = 2; i < 10000; i++) {
        if (dp[i]) continue;
        dp[i] = LONG_LONG_MAX;
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], (dp[j] + dp[i - j]) % MOD);
        }
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}