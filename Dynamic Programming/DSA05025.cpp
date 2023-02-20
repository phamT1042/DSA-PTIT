#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long dp[n + 1]; 
        for (int i = 0; i < n + 1; i++) dp[i] = 0;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 3; j < i; j++) {
                if (j >= 0) {
                    dp[i] += dp[j];
                }
            }
        }
        cout << dp[n] << endl;
    }
}