#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[n], dp[n][k];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= k;
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < k; j++) dp[i][j] = INT_MIN;
        dp[0][a[0]] = 1;
        for (int i = 1; i < n; i++) 
            for (int j = 0; j < k; j++) 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - a[i]) % k] + 1);
        cout << dp[n - 1][0] << '\n';
    }
    return 0;
}