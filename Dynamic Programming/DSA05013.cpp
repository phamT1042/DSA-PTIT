#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    long long MOD = 1e9 + 7;
    while (t--) {
        int n, k; cin >> n >> k;
        long long dp[n + 1]; //Số cách đi đến bậc thang thứ i
        for (int i = 0; i < n + 1; i++) dp[i] = 0;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i - k; j < i; j++) {
                if (j >= 0) {
                    dp[i] += dp[j];
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[n] << endl;
    }
}